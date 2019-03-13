#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
SoftwareSerial obdSerial(3, 2); // RX, TX
SoftwareSerial dddSerial(5, 4); // drug detection device

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
char rpmHexCharArr[19];
String reply;

//bool intoxicated = false;
bool intoxicated = true;

void setup() {
  // Open serial communications:
  Serial.begin(38400);
  //Serial.println("Master!");
  
  // Baud rate for command mode
  obdSerial.begin(38400);
//  dddSerial.begin(38400);

  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
 
  //Display Welcome Message
  lcd.setCursor(0, 0);
  lcd.print(F("Drugless Driving"));
  lcd.setCursor(0, 1);
  lcd.print(F("Welcome"));
  delay(1000);
//  lcd.clear();

  //set up LED
  pinMode(LED, OUTPUT);
  digitalWrite(LED, ledOn);
}

void loop() {
  if (responded) {
    if (flag == 0) {
      Serial.write("AT\r\n");
      obdSerial.write("AT\r\n");
      responded = 0;
    } else if (flag == 1) {
      Serial.write("AT+ORGL\r\n");
      obdSerial.write("AT+ORGL\r\n");
      responded = 0;
    } else if (flag == 2) {
      Serial.write("AT+CMODE=0\r\n");
      obdSerial.write("AT+CMODE=0\r\n");
      responded = 0;
    } else if (flag == 3) {
      Serial.write("AT+ROLE=1\r\n");
      obdSerial.write("AT+ROLE=1\r\n");
      responded = 0;
    } else if (flag == 4) {
      Serial.write("AT+BIND=18,E5,48730\r\n");
      obdSerial.write("AT+BIND=18,E5,48730\r\n");
      responded = 0;
    } else if (flag == 5) {
      Serial.write("AT+INIT\r\n");
      obdSerial.write("AT+INIT\r\n");
      responded = 0;
    } else if (flag == 6) {
      Serial.write("AT+PAIR=18,E5,48730,48\r\n");
      obdSerial.write("AT+PAIR=18,E5,48730,48\r\n");
      responded = 0;
    } else if (flag == 7) {
      Serial.write("AT+LINK=18,E5,48730\r\n");
      obdSerial.write("AT+LINK=18,E5,48730\r\n");
      responded = 0;
    } else if (flag == 8) {
//      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(F("Connected...    "));
      lcd.setCursor(0, 1);
      lcd.print(F("                "));

      ledOn = false;
      digitalWrite(LED, ledOn);
      delay(1000);
      flag++;
    } else if (flag == 9){
//      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(F("Blow into Device"));
      lcd.setCursor(0, 1);
      lcd.print(F("                "));
      inquiry = "08 0C"; // Want car to be stopped while testing... the problem is the setup before bluetooth is established
      // This is where we'd check if the user is intoxicated 
      delay(2000);
      flag++;
    } else if (flag == 10){
      if (intoxicated) {
//        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(F("Intoxicated...  "));
        lcd.setCursor(0,1);
        lcd.print(F("Engine Shut Off"));
        inquiry = "08 0C";
        flag++;
      } else {
//        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(F("Clear to Drive! "));
        lcd.setCursor(0,1);
        lcd.print(F("Safe Driving    "));
        inquiry = "01 0C"; // Theoretically, we'd just want to not send the command to set the RPM to 0
      }
    } else if (flag == 11){
        delay(2000);
        lcd.setCursor(0,0);
        lcd.print(F("Are We Wrong?  "));
        lcd.setCursor(0,1);
        lcd.print(F("Try Again...   "));
        delay(2000);
        flag = 9;
        inquiry = "";
    }
  } else {
//    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Establishing    "));
    lcd.setCursor(0, 1);
    lcd.print(F("Connection...   "));

    blinkTime++;
    if (blinkTime > 100){
      blinkTime = 0;
      ledOn = !ledOn;
//      Serial.println("blink");
      digitalWrite(LED, ledOn);
    }
  }

//  if (obdSerial.available()) {
//    while(obdSerial.available()) { // While there is more to be read, keep reading.
//      command += (char)obdSerial.read();
//    }
//    
//    Serial.println(command);
//    command = ""; // No repeats
//    responded = 1;
//    flag++;
//  }

  if (obdSerial.available()) {
    command = ""; // No repeats
    while(obdSerial.available()) { // While there is more to be read, keep reading.
      command += (char)obdSerial.read();
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
//    rpmHexStr = String(rpm, HEX);
    reply = F("41 0C ");
//    sprintf(rpmHexCharArr, "%02x %02x %02x %02x", rpm/4/256, rpm/4 % 256, 0, 0);
    sprintf(rpmHexCharArr, "%02x %02x", rpm/4/256, rpm/4 % 256);
    reply.concat(rpmHexCharArr);
    reply.toUpperCase();
    Serial.println(reply);
//      lcd.setCursor(0,1);
//      lcd.print(reply);
  }
}


