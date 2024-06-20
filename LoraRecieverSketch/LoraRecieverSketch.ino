#include <SPI.h>
#include <LoRa.h>

bool DEBUG = true;

void setup() {
  if(DEBUG) Serial.begin(9600);
  if(DEBUG) while (!Serial);

  Serial.println("LoRa Sender");

  while (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa failed!, trying again...");
  }
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
