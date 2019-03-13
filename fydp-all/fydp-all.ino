#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
SoftwareSerial mySerial(4, 2); // RX, TX

String command = ""; // Stores response of the HC-05 Bluetooth device
int flag = 0, responded = 1;

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13, columns = 16, rows = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int LED = 6;
int ledOn = 1;
bool blinkTime = true;

String inquiry = "";
int rpm;
String rpmHexStr;
String reply;

void setup() {
  // Open serial communications:
  Serial.begin(38400);
  //Serial.println("Master!");
  
  // Baud rate for command mode
  mySerial.begin(38400);

  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
 
  //Display Welcome Message
  lcd.setCursor(0, 0);
  lcd.print("Drugless Driving");
  lcd.setCursor(0, 1);
  lcd.print("Welcome");
  delay(1000);
  lcd.clear();

  //set up LED
  pinMode(LED, OUTPUT);
  digitalWrite(LED, ledOn);
}

void loop() {
  if (responded) {
    if (flag == 0) {
      Serial.write("AT\r\n");
      mySerial.write("AT\r\n");
      responded = 0;
    } else if (flag == 1) {
      Serial.write("AT+ORGL\r\n");
      mySerial.write("AT+ORGL\r\n");
      responded = 0;
    } else if (flag == 2) {
      Serial.write("AT+CMODE=0\r\n");
      mySerial.write("AT+CMODE=0\r\n");
      responded = 0;
    } else if (flag == 3) {
      Serial.write("AT+ROLE=1\r\n");
      mySerial.write("AT+ROLE=1\r\n");
      responded = 0;
    } else if (flag == 4) {
      Serial.write("AT+BIND=18,E5,48730\r\n");
      mySerial.write("AT+BIND=18,E5,48730\r\n");
      responded = 0;
    } else if (flag == 5) {
      Serial.write("AT+INIT\r\n");
      mySerial.write("AT+INIT\r\n");
      responded = 0;
    } else if (flag == 6) {
      Serial.write("AT+PAIR=18,E5,48730,48\r\n");
      mySerial.write("AT+PAIR=18,E5,48730,48\r\n");
      responded = 0;
    } else if (flag == 7) {
      Serial.write("AT+LINK=18,E5,48730\r\n");
      mySerial.write("AT+LINK=18,E5,48730\r\n");
      responded = 0;
    } else if (flag == 8) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Connected...    ");
      lcd.setCursor(0, 1);
      lcd.print("                ");

      ledOn = false;
      digitalWrite(LED, ledOn);
      delay(1000);
      flag++;
    } else if (flag == 9){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Blow into Device");
      flag++;
    } else if (flag == 10){
      inquiry = "01 0C";
    }
  } else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Establishing    ");
    lcd.setCursor(0, 1);
    lcd.print("Connection...   ");

    blinkTime++;
    if (blinkTime > 100){
      blinkTime = 0;
      ledOn = !ledOn;
      Serial.println("blink");
      digitalWrite(LED, ledOn);
    }
  }

//  if (mySerial.available()) {
//    while(mySerial.available()) { // While there is more to be read, keep reading.
//      command += (char)mySerial.read();
//    }
//    
//    Serial.println(command);
//    command = ""; // No repeats
//    responded = 1;
//    flag++;
//  }

  if (mySerial.available()) {
    command = ""; // No repeats
    while(mySerial.available()) { // While there is more to be read, keep reading.
      command += (char)mySerial.read();
    }

    

//    lcd.clear();
//    lcd.setCursor(0,0);
//    lcd.print(command);
    responded = 1;
    flag++;
  }
  
  if (inquiry.length() > 0){
    Serial.println(inquiry);
//      lcd.clear();
//      lcd.setCursor(0,0);
//      lcd.print(inquiry);
    if (inquiry == "01 0C") {
      rpm = 4 * random(0, 8191);
    } else if (inquiry == "08 0C") {
      rpm = 0;
    }
    rpmHexStr = String(rpm, HEX);
    reply = "41 0C ";
    reply.concat(rpmHexStr);
    Serial.println(reply);
//      lcd.setCursor(0,1);
//      lcd.print(reply);
  }
}
