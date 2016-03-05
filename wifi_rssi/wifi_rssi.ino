#include <Arduino.h>
#include <ESP8266WiFi.h>

const char* SSID = "osuwireless";
const uint8_t BSSID[6] = {0x18, 0x64, 0x72, 0x50, 0x9a, 0x80};

// Return RSSI or 0 if target SSID not found
int32_t getRSSI(const char* target_ssid) {
  byte available_networks = WiFi.scanNetworks();

  for (int network = 0; network < available_networks; network++) {
    char received_ssid[50];
    WiFi.SSID(network).toCharArray(received_ssid, 50);
    if (strcmp(received_ssid, target_ssid) == 0) {
      bool match = true;
      for (int i = 0; i < 6; i++) {
        match = WiFi.BSSID(network)[i] ==BSSID[i];
        if (!match) break;
      }
      if (match) return WiFi.RSSI(network);
    }
  }
  return 0;
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  unsigned long before = millis();
  int32_t rssi = getRSSI(SSID);
  unsigned long after = millis();
  //Serial.print("Signal strength: ");
  Serial.println(rssi);
  //Serial.println("dBm");

  //Serial.print("Took ");
  //Serial.print(after - before);
  //Serial.println("ms");
  delay(50);
}
