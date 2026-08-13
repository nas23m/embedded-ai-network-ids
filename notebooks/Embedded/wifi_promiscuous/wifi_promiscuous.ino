#include <WiFi.h>
#include <cstring>
#include "esp_wifi.h"
#include "../../RF_Inference_for_arduino.cpp"

ConnectionBuffer connectionBuffer;

void wifi_sniffer_callback(void* buf, wifi_promiscuous_pkt_type_t type) {
  if (type != WIFI_PKT_DATA) {
    return;
  }

  wifi_promiscuous_pkt_t* pkt = (wifi_promiscuous_pkt_t*)buf;

  uint8_t* payload = pkt->payload;

  uint16_t etherType = (payload[30] << 8) | payload[31];

  if (etherType != 0x0800) {
    return;
  }
  
  uint8_t protocol = payload[32 + 9];
  int protocolTypeInt;
  if (protocol == 6) {
    protocolTypeInt = 1;
  } else if (protocol == 17) {
    protocolTypeInt = 2;
  } else if (protocol == 1) {
    protocolTypeInt = 0;
  } else {
    protocolTypeInt = 3;
  }

  uint32_t sourceIP = (payload[32 + 12] << 24) | (payload[32 + 13] << 16) | (payload[32 + 14] << 8) | payload[32 + 15];

  uint32_t destinationIP = (payload[32 + 16] << 24) | (payload[32 + 17] << 16) | (payload[32 + 18] << 8) | payload[32 + 19];

  uint16_t sourcePort = (payload[52] << 8) | payload[52 + 1];

  uint16_t destinationPort = (payload[52 + 2] << 8) | payload[52 + 3];

  uint8_t tcpFlags = payload[52 + 13];

  char flags[8];
  if(tcpFlags & 0x04) {
    strcpy(flags, "REJ");
  } else if(tcpFlags & 0x01) {
    strcpy(flags, "SF");
  } else if ((tcpFlags & 0x02) && (tcpFlags & 0x10)) {
    strcpy(flags, "S1");
  } else if (tcpFlags & 0x02) {
    strcpy(flags, "S0");
  } else{
    strcpy(flags, "SF");
  }

  char serviceStr[16];
  if (destinationPort == 80) {
    strcpy(serviceStr, "http");
  } else if (destinationPort == 443) {
    strcpy(serviceStr, "http_443");
  } else if (destinationPort == 21) {
    strcpy(serviceStr, "ftp");
  } else if (destinationPort == 22) {
    strcpy(serviceStr, "ssh");
  } else if (destinationPort == 25) {
    strcpy(serviceStr, "smtp");
  } else if (destinationPort == 53) {
    strcpy(serviceStr, "domain_u");
  } else {
    strcpy(serviceStr, "other");
  }

  
  Connection conn = {
    millis() / 1000.0,
    sourceIP,
    destinationIP,
    sourcePort,
    "",
    "",
    0.0,
    protocolTypeInt,
    0.0,
    0.0,
    0,
    0,
    0
};
strcpy(conn.service, serviceStr);
strcpy(conn.flag, flags);

double output[2];
connectionBuffer.predict(conn, output);

Serial.print("Prob normal: ");
Serial.println(output[0]);
Serial.print("Prob attack: ");
Serial.println(output[1]);

}




void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_MODE_STA);
  esp_wifi_set_promiscuous(true);
  esp_wifi_set_promiscuous_rx_cb(&wifi_sniffer_callback);

  esp_wifi_set_channel(6, WIFI_SECOND_CHAN_NONE);

}

void loop() {
  delay(1000);

}
