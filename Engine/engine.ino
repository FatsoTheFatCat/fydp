#include "EngineHandler.hpp"
#include <SoftwareSerial.h>

SoftwareSerial BleSoftwareSerial(4,2);
String message;
EngineHandler eh(&BleSoftwareSerial);

void setup() {
  Serial.println("Begin");
}
 
void loop() {
  
}
