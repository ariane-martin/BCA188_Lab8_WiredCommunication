#include <Arduino.h>

const int UART_RX = 16;
const int UART_TX = 17;

unsigned long previousMillis = 0;
const unsigned long interval = 1000;

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, UART_RX, UART_TX);

  Serial.println("UART Loopback Test Started");
  Serial.println("Connect GPIO17 (TX) to GPIO16 (RX).");
}

void loop() {
  if (millis() - previousMillis >= interval) {
    previousMillis = millis();

    Serial2.println("PING");
    Serial.println("Sent: PING");
  }

  while (Serial2.available() > 0) {
    char received = Serial2.read();
    Serial.write(received);
  }
}