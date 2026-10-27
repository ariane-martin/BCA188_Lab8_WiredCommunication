# BCA188 – Laboratory 8: Wired Communication

## 1. Objective

The objective of this laboratory is to test three wired communication interfaces supported by the ESP32: UART, I²C, and SPI.

## 2. Materials

- ESP32 development board
- USB cable
- Jumper wires
- I²C OLED display
- Computer with Arduino IDE

## 3. Pin Connections

| Interface | ESP32 Pin | Connection |
|---|---|---|
| UART TX | GPIO17 | GPIO16 (RX) |
| UART RX | GPIO16 | GPIO17 (TX) |
| I²C SDA | GPIO21 | OLED SDA |
| I²C SCL | GPIO22 | OLED SCL |
| SPI SCK | GPIO18 | SPI clock |
| SPI MISO | GPIO19 | GPIO23 (MOSI) for loopback |
| SPI MOSI | GPIO23 | GPIO19 (MISO) for loopback |
| SPI CS | GPIO5 | Chip Select |

## 4. Procedures

### A. UART Loopback

The ESP32 transmitted `PING` using Serial2 at 9600 baud. GPIO17 (TX) was connected to GPIO16 (RX). The received message was displayed through the USB Serial Monitor.

### B. I²C Scanner

The ESP32 scanned I²C addresses using GPIO21 (SDA) and GPIO22 (SCL). The OLED display was connected to verify device detection.

### C. SPI Loopback

The ESP32 transmitted byte `0xA5` using SPI with GPIO23 (MOSI) connected to GPIO19 (MISO). The transmitted and received bytes were compared.

## 5. Observation Results

| Test | Condition | Actual Observation |
|---|---|---|
| UART | Jumper connected | `PING` was transmitted and echoed back. |
| UART | Jumper disconnected | Only `Sent: PING` appeared; no echo was received. |
| I²C | OLED connected | The scanner detected the OLED's I²C address. |
| I²C | OLED disconnected | `No I2C devices found` appeared. |
| SPI | Jumper connected | Sent `0xA5`; received `0xA5`. PASS displayed. |
| SPI | Jumper disconnected | Sent `0xA5`; received `0x0`. FAIL displayed. |

## 6. Guide Questions

### 1. Why does UART need both sides to use the same baud rate, while SPI uses a clock line?

UART does not use a separate clock line, so both devices must use the same baud rate to interpret the transmitted bits correctly. SPI uses a clock signal to synchronize data transmission.

### 2. Why can't two devices with the same address share one I²C bus?

Devices with the same address can respond to the same request, causing addressing conflicts. Different addresses are generally needed to communicate with individual devices on the same bus.

### 3. Why is CS set HIGH between SPI transfers?

CS is set HIGH to deselect the SPI device after a transfer. It is set LOW when the device is selected for communication.

## 7. Evidence

Screenshots of the Serial Monitor outputs and hardware connections will be included in the `evidence/` folder.

- UART loopback output
- I²C scanner output
- SPI loopback output

## 8. Conclusion

The laboratory demonstrated UART, I²C, and SPI communication using the ESP32. UART successfully echoed transmitted messages, the I²C scanner detected the OLED device, and SPI successfully returned the transmitted byte when the loopback jumper was connected. The tests demonstrated how physical connections affect wired communication.
