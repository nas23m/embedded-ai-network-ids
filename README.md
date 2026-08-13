# Embedded AI Network Intrusion Detection System (ESP32)

An ESP32-based Network Intrusion Detection System (NIDS) that runs a machine
learning model **entirely on-device** — no cloud, no external server, no
dependency on internet connectivity. Raw WiFi traffic is captured, converted
into 28 statistical features in real time, and classified as normal or attack
by a Random Forest model compiled directly into the firmware as native C code.

## Why this project

Most intrusion detection systems assume abundant compute — a server, a GPU,
a constant network connection to a SIEM. This project asks a narrower
question: how much of that pipeline can be pushed onto a $5 microcontroller?

Building it required combining three areas that don't usually meet in one
project: machine learning (training and compressing a model small enough to
embed), network security (understanding what actually distinguishes an
attack from normal traffic, at the protocol level), and low-level embedded
systems (memory-constrained C++, no dynamic allocation, no OS, real-time
packet parsing at the byte level).

## Architecture

```
Raw WiFi packet (802.11)
        │
        ▼
ESP32 promiscuous-mode capture (esp_wifi_set_promiscuous_rx_cb)
        │
        ▼
Byte-level parsing → IPv4 / TCP header extraction
   (source/dest IP, ports, protocol, TCP flags → NSL-KDD flag category,
    destination port → service category)
        │
        ▼
C++ rolling-feature engine (fixed-size circular buffer, no heap allocation)
   - 2-second time-window statistics (count, error rates, same-service rate...)
   - 100-connection host-window statistics (dst_host_count, dst_host_serror_rate...)
   → 19 computed features
        │
        ▼
28-feature vector assembled (9 direct + 19 computed)
        │
        ▼
Random Forest classifier (trained in Python, converted to native C)
        │
        ▼
Prediction: {P(normal), P(attack)} → printed over Serial
```

## Results

| Metric | Value |
|---|---|
| Model accuracy (NSL-KDD test set) | 76.7% |
| Model size (compressed) | 70 KB |
| Features used | 28 of 41 (13 dropped — required deep packet inspection infeasible on-device) |
| Firmware flash usage | 893,800 / 1,310,720 bytes (68%) |
| Firmware RAM usage | 54,160 / 327,680 bytes (16%) |

The 76.7% accuracy is consistent with published NSL-KDD benchmarks — the test
set deliberately includes attack types absent from training, so it measures
generalization rather than memorization.

## Pipeline

1. **Data & training** (`notebooks/`) — NSL-KDD dataset, binary classification
   (normal vs. attack), Random Forest with class-weight balancing and
   depth/estimator tuning to hit the embedded size budget.
2. **Feature reduction** — of the dataset's 41 original features, 13 requiring
   full session/payload inspection (e.g. `num_failed_logins`, `root_shell`)
   were dropped as infeasible for a single-packet-at-a-time embedded capture.
   Retraining on the remaining 28 confirmed accuracy held (76.6% → 76.7%).
3. **Model → C conversion** (`models/rf_model_reduced.c`) — the trained
   scikit-learn model converted to plain C (via `m2cgen`), then verified
   with a test harness confirming bit-for-bit matching predictions against
   the original Python model on held-out samples.
4. **C++ feature engine** (`notebooks/RF_Inference_for_arduino.cpp`) — a
   hand-built, from-scratch reimplementation of the dataset's rolling-window
   feature definitions (KDD Cup 99 / NSL-KDD spec), using a fixed-size
   circular buffer — no dynamic memory allocation, suitable for continuous
   embedded operation.
5. **Firmware** (`notebooks/Embedded/wifi_promiscuous/`) — ESP32 WiFi
   promiscuous-mode packet capture, byte-level IPv4/TCP header parsing, and
   integration with the feature engine + model for live, on-device inference.

## Tech stack

- **Python** — pandas, scikit-learn (data prep, model training)
- **m2cgen** — model-to-C conversion
- **C / C++** — embedded feature engineering, model inference
- **ESP32 (Arduino / ESP-IDF)** — WiFi promiscuous capture, deployment target

## Repository structure

```
├── notebooks/              Python: data loading, training, model conversion,
│                            C/C++ feature-engine prototypes and tests
├── models/                  Trained model (.joblib), converted C model,
│                            generated test vectors for correctness verification
├── notebooks/Embedded/      Arduino sketch + firmware-side C++/C sources
└── .gitignore
```

## Reproducing this

1. Download the NSL-KDD dataset (`KDDTrain+.txt`, `KDDTest+.txt`) into `data/`
2. `pip install -r requirements.txt` *(numpy, pandas, scikit-learn, m2cgen, joblib)*
3. Run `notebooks/RF_Binary_Train_choice.py` to train and export the model
4. Run `notebooks/Joblib_to_c.py` to generate the C source
5. Run `notebooks/Generate_test_vectors_for_c.py` + compile the test harness
   to verify the C conversion matches Python predictions exactly
6. Open `notebooks/Embedded/wifi_promiscuous/wifi_promiscuous.ino` in Arduino
   IDE (ESP32 board package installed), select **ESP32 Dev Module**, and flash

## Known limitations

Documenting these honestly, since they're deliberate scoping decisions, not
oversights:

- **TCP flag approximation** — the dataset's `flag` feature represents a full
  connection's outcome (e.g. handshake completed, connection refused), but a
  single captured packet only shows one moment. Flags are approximated from
  individual packet bits (SYN/ACK/RST/FIN) rather than tracked across a full
  session — a simplification, not a full TCP state machine.
- **Fixed 802.11 header offset** — packet parsing assumes a standard 24-byte
  WiFi header; real 802.11 frames can vary in length (QoS fields, etc.),
  which isn't accounted for.
- **Single-channel listening** — the ESP32 radio listens on one WiFi channel
  at a time; traffic on other channels isn't observed.
- **Placeholder fields** — `duration`, `land`, and `wrong_fragment` require
  tracking a connection across multiple packets over time; these currently
  default to 0 rather than being computed live.
- **Service inference from port only** — the `service` feature is mapped from
  a small set of well-known destination ports; uncommon services fall back to
  a generic "other" category.

## Future work

- Full session-state tracking to properly compute `duration` and TCP flags
- Multi-channel scanning (cycling through WiFi channels)
- Live attack simulation and detection-rate measurement (nmap/hping3 against
  the deployed device)
- On-device alerting (LED, buzzer, or MQTT publish) instead of Serial-only output
