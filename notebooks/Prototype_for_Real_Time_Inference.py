"""
Prototype: compute time-window and host-window derived features
from a stream of connection records, mimicking what the ESP32
firmware will need to do in C++.

Each connection record is a dict with:
    timestamp   : float (seconds)
    src_ip      : str
    dst_ip      : str
    src_port    : int
    service     : str   (e.g. "http", "ftp_data")
    flag        : str   (e.g. "SF", "S0", "REJ", ...)

SYN-error flags (connection attempt failed): S0, S1, S2, S3
REJ-error flag (connection actively refused): REJ
"""

from collections import deque

SYN_ERROR_FLAGS = {"S0", "S1", "S2", "S3"}
REJ_ERROR_FLAG = "REJ"


class RollingFeatureWindow:
    def __init__(self, time_window_sec=2.0, host_window_size=100):
        self.time_window_sec = time_window_sec
        self.host_window_size = host_window_size
        # single buffer, we filter it two different ways
        self.buffer = deque(maxlen=1000)  # generous cap, time-filtered below

    def add_and_compute(self, conn):
        """
        Add a new connection record and compute all derived features
        for it, based on the buffer state *before* this connection
        (i.e. using history, not including itself twice).
        """
        features = self._compute_features(conn)
        self.buffer.append(conn)
        return features

    # -----------------------------------------------------------------
    # Time-window group (last N seconds, same dst host / same service)
    # -----------------------------------------------------------------
    def _time_window(self, conn):
        cutoff = conn["timestamp"] - self.time_window_sec
        return [c for c in self.buffer if c["timestamp"] >= cutoff]

    # -----------------------------------------------------------------
    # Host-window group (last 100 connections, filtered by dst host)
    # -----------------------------------------------------------------
    def _host_window(self, conn):
        recent = list(self.buffer)[-self.host_window_size:]
        return [c for c in recent if c["dst_ip"] == conn["dst_ip"]]

    def _compute_features(self, conn):
        f = {}

        # ---- time-window features ----
        tw = self._time_window(conn)
        count = sum(1 for c in tw if c["dst_ip"] == conn["dst_ip"])
        srv_count = sum(1 for c in tw if c["service"] == conn["service"])

        count_group = [c for c in tw if c["dst_ip"] == conn["dst_ip"]]
        srv_group = [c for c in tw if c["service"] == conn["service"]]

        f["count"] = count
        f["srv_count"] = srv_count
        f["serror_rate"] = self._error_rate(count_group, SYN_ERROR_FLAGS)
        f["srv_serror_rate"] = self._error_rate(srv_group, SYN_ERROR_FLAGS)
        f["rerror_rate"] = self._error_rate(count_group, {REJ_ERROR_FLAG})
        f["srv_rerror_rate"] = self._error_rate(srv_group, {REJ_ERROR_FLAG})
        f["same_srv_rate"] = srv_count / count if count else 0.0
        f["diff_srv_rate"] = 1 - f["same_srv_rate"]
        f["srv_diff_host_rate"] = (
            sum(1 for c in srv_group if c["dst_ip"] != conn["dst_ip"]) / srv_count
            if srv_count else 0.0
        )

        # ---- host-window features ----
        hw = self._host_window(conn)
        dst_host_count = len(hw)
        dst_host_srv_group = [c for c in hw if c["service"] == conn["service"]]
        dst_host_srv_count = len(dst_host_srv_group)

        f["dst_host_count"] = dst_host_count
        f["dst_host_srv_count"] = dst_host_srv_count
        f["dst_host_same_srv_rate"] = (
            dst_host_srv_count / dst_host_count if dst_host_count else 0.0
        )
        f["dst_host_diff_srv_rate"] = 1 - f["dst_host_same_srv_rate"]
        f["dst_host_same_src_port_rate"] = (
            sum(1 for c in hw if c["src_port"] == conn["src_port"]) / dst_host_count
            if dst_host_count else 0.0
        )
        f["dst_host_srv_diff_host_rate"] = (
            sum(1 for c in dst_host_srv_group if c["src_ip"] != conn["src_ip"]) / dst_host_srv_count
            if dst_host_srv_count else 0.0
        )
        f["dst_host_serror_rate"] = self._error_rate(hw, SYN_ERROR_FLAGS)
        f["dst_host_srv_serror_rate"] = self._error_rate(dst_host_srv_group, SYN_ERROR_FLAGS)
        f["dst_host_rerror_rate"] = self._error_rate(hw, {REJ_ERROR_FLAG})
        f["dst_host_srv_rerror_rate"] = self._error_rate(dst_host_srv_group, {REJ_ERROR_FLAG})

        return f

    @staticmethod
    def _error_rate(group, error_flags):
        if not group:
            return 0.0
        errors = sum(1 for c in group if c["flag"] in error_flags)
        return errors / len(group)


# -----------------------------------------------------------------
# Quick manual test with synthetic traffic
# -----------------------------------------------------------------
if __name__ == "__main__":
    window = RollingFeatureWindow()

    synthetic_traffic = [
        {"timestamp": 0.0, "src_ip": "192.168.1.10", "dst_ip": "10.0.0.5",
         "src_port": 5000, "service": "http", "flag": "SF"},
        {"timestamp": 0.5, "src_ip": "192.168.1.10", "dst_ip": "10.0.0.5",
         "src_port": 5001, "service": "http", "flag": "SF"},
        {"timestamp": 0.8, "src_ip": "192.168.1.11", "dst_ip": "10.0.0.5",
         "src_port": 5002, "service": "http", "flag": "S0"},  # SYN error
        {"timestamp": 1.9, "src_ip": "192.168.1.12", "dst_ip": "10.0.0.5",
         "src_port": 5003, "service": "ftp_data", "flag": "REJ"},  # REJ error
    ]

    for conn in synthetic_traffic:
        feats = window.add_and_compute(conn)
        print(f"\nConnection at t={conn['timestamp']} -> {conn['dst_ip']} ({conn['service']})")
        for k, v in feats.items():
            print(f"  {k}: {v}")