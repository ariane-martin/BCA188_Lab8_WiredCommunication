#include <Arduino.h>
#include <SPI.h>

const int SCK_PIN = 18;
const int MISO_PIN = 19;
const int MOSI_PIN = 23;
const int CS_PIN = 5;

SPISettings spiSettings(1000000, MSBFIRST, SPI_MODE0);

void setup() {
  Serial.begin(115200);

  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);

  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);

  Serial.println("SPI Loopback Test Started");
  Serial.println("Connect GPIO23 (MOSI) to GPIO19 (MISO).");
}

void loop() {
  byte sentByte = 0xA5;
  byte receivedByte;

  SPI.beginTransaction(spiSettings);

  digitalWrite(CS_PIN, LOW);
  receivedByte = SPI.transfer(sentByte);
  digitalWrite(CS_PIN, HIGH);

  SPI.endTransaction();

  Serial.print("Sent: 0x");
  Serial.print(sentByte, HEX);

  Serial.print(" | Received: 0x");
  Serial.println(receivedByte, HEX);

  if (receivedByte == sentByte) {
    Serial.println("PASS: SPI loopback successful");
  } else {
    Serial.println("FAIL: Check MOSI-MISO jumper");
  }

  delay(1000);
}