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
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(5000);
}
