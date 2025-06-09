# Trolley with Automatic Billing System

This project implements an RFID-based smart trolley system using Arduino, allowing automatic item detection and price calculation. Items are identified using RFID cards, and the total cost is displayed on an LCD. A buzzer provides feedback when an item is scanned.

## Features
- RFID-based item recognition
- LCD display for item name and total amount
- Buzzer for feedback on item scan
- Serial monitoring for debugging

## Components Used
- **Arduino Uno**
- **MFRC522 RFID Reader**
- **LCD (16x2)**
- **SPI Communication**
- **Buzzer**
- **RFID Tags**

## Installation & Setup
1. Install the required libraries:
   - [MFRC522 Library](https://github.com/miguelbalboa/rfid)
   - [LiquidCrystal Library](https://www.arduino.cc/en/Reference/LiquidCrystal)

2. Upload the code to the Arduino using the Arduino IDE.

3. Connect the components as per the circuit diagram.

4. Power on the Arduino and scan RFID cards to test the system.

## Usage
- Place an RFID card near the reader.
- The LCD will display the corresponding item and price.
- If the card is unrecognized, "Access Denied" will be displayed.
- The total amount updates in real-time.

