#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
#define SS_PIN 10
#define RST_PIN 9
#define BUZZER_PIN 8
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522
instance.
// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int totalAmount = 0;
void setup() {
 Serial.begin(9600); // Initiate a serial
communication
SPI.begin(); // Initiate SPI bus
mfrc522.PCD_Init(); // Initiate MFRC522
 Serial.println("Approximate your card to the reader..."); 
 Serial.println();
 // Set up the LCD's number of columns and rows:
 lcd.begin(16, 2);
 lcd.print("smart trolley");
pinMode(BUZZER_PIN, OUTPUT);
}
void loop() {
//Turn off the
display
lcd.noDisplay();
delay(500);
// Turn on the
display:
 lcd.display();
delay(500);
 // Look for new cards if
(!mfrc522.PICC_IsNewCardPrese
nt)) {
 return;
 } 
 // Select one of the cards if
(!mfrc522.PICC_ReadCardSeri
al()) {
return;
 }
 // Show UID on serial
monitor
lcd.setCursor(0,0);
Serial.print("UID tag: ");
lcd.print("UID: ");
String content = "";
byte let er;
 for (byte i = 0; i < mfrc522.uid.size; i++) {
 Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
 Serial.print(mfrc522.uid.uidByte[i], HEX);
 lcd.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
 lcd.print(mfrc522.uid.uidByte[i], HEX);
 content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : "
"));
 content.concat(String(mfrc522.uid.uidByte[i], HEX));
 }
 Serial.println();
Serial.print("Message: "); 
lcd.print("Message: ");
content.toUpperCase();
 if (content.substring(1) == "ED 1E D1 FC") {
 lcd.setCursor(0, 1);
 Serial.println("Authorizedaccess");
 lcd.print("SNICKERS ");
 totalAmount += 30;
 digitalWrite(BUZZER_PIN,
HIGH);
 delay(1000);
 digitalWrite(BUZZER_PIN, LOW);
 delay(2000);
 }
else if (content.substring(1) == "AC A1 FE 37") {
 lcd.setCursor(0, 1);
 Serial.println("Authorized access");
 lcd.print("DAIRY MILK ");
 totalAmount += 40;
 digitalWrite(BUZZER_PIN, HIGH);
 delay(1000); digitalWrite(BUZZER_PIN,
LOW); 
delay(2000);
 }
else if (content.substring(1) == "12 4B 4C 1B") {
 lcd.setCursor(0, 1);
 Serial.println("Authorized
access");
 lcd.print("KITKAT ");
 totalAmount+=10;
digitalWrite(BUZZER_PIN,
HIGH);
 delay(1000);
digitalWrite(BUZZER_PIN,
LOW);
 delay(2000);
}
else
{
 lcd.setCursor(1);
 Serial.println("Access
denied");
 lcd.print("Access denied ");
 digitalWrite(BUZZER_PIN,
HIGH); 
delay(1000);
digitalWrite(BUZZER_PIN,
LOW);
 delay(2000);
 }
 Serial.print("Total amount: Rs ");
 Serial.println(totalAmount);
 lcd.setCursor(0, 1);
 lcd.print("Total: Rs ");
lcd.print(totalAmount);
} 