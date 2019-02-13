#include <SoftwareSerial.h>
SoftwareSerial mySerial(4, 2); // RX, TX

String command = ""; // Stores response of the HC-05 Bluetooth device
int flag = 0, responded = 1;

void setup() {
  // Open serial communications:
  Serial.begin(38400);
  Serial.println("Master!");
  
  // Baud rate for command mode
  mySerial.begin(38400);
}

void loop() {
  if (responded) {
    if (flag == 0) {
      Serial.write("AT\r\n");
      mySerial.write("AT\r\n");
      responded = 0;
    } else if (flag == 1) {
      Serial.write("AT+INIT\r\n");
      mySerial.write("AT+INIT\r\n");
      responded = 0;
    } else if (flag == 2) {
      Serial.write("AT+CMODE=1\r\n");
      mySerial.write("AT+CMODE=1\r\n");
      responded = 0;
    } else if (flag == 3) {
      Serial.write("AT+ROLE=1\r\n");
      mySerial.write("AT+ROLE=1\r\n");
      responded = 0;
    } else if (flag == 4) {
      Serial.write("AT+INQ\r\n");
      mySerial.write("AT+INQ\r\n");
      responded = 0;
    } else if (flag == 5) {
      // +INQ:18:E5:48730,1F00,7FFF
      Serial.write("AT+RNAME?18,E5,48730\r\n");
      mySerial.write("AT+RNAME?18,E5,48730\r\n");
      responded = 0;
    } else if (flag == 6) {
      Serial.write("AT+BIND=18,E5,48730\r\n");
      mySerial.write("AT+BIND=18,E5,48730\r\n");
      responded = 0;
    } else if (flag == 7) {
      Serial.write("AT+PAIR=18,E5,48730,48\r\n");
      mySerial.write("AT+PAIR=18,E5,48730,48\r\n");
      responded = 0;
    } else if (flag == 8) {
      delay(1000);
      Serial.write("AT+STATE\r\n");
      mySerial.write("AT+STATE\r\n");
      responded = 0;
    } else if (flag == 9) {
      delay(1000);
      Serial.write("AT+LINK=18,E5,48730\r\n");
      mySerial.write("AT+LINK=18,E5,48730\r\n");
      responded = 0;
    }
  }

  if (mySerial.available()) {
    while(mySerial.available()) { // While there is more to be read, keep reading.
      command += (char)mySerial.read();
    }
    
    Serial.println(command);
    command = ""; // No repeats
    responded = 1;
    flag++;
  }
}
