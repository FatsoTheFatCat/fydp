#include <SoftwareSerial.h>
SoftwareSerial mySerial(4, 2); // RX, TX

String command = ""; // Stores response of the HC-05 Bluetooth device


void setup() {
  // Open serial communications:
  Serial.begin(38400);
  Serial.println("Type AT commands!");
  
  // Baud rate for command mode
  mySerial.begin(38400);
}

void loop() {
  // Read device output if available.
  if (mySerial.available()) {
    while(mySerial.available()) { // While there is more to be read, keep reading.
      command += (char)mySerial.read();
    }
    
    Serial.println(command);
    command = ""; // No repeats
  }
  
  // Read user input if available.
  if (Serial.available()){
    delay(10); // The delay is necessary to get this working!
    mySerial.write(Serial.read());
  }
}
