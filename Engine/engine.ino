#include "EngineHandler.hpp"

String message;
EngineHandler eh;


void setup() {
 
  Serial.begin(9600);
  eh = EngineHandler();
  
}
 
void loop() {
  while(Serial.available())
  {//while there is data available on the serial monitor
    message+=char(Serial.read());//store string from serial command
  }
  if(!Serial.available())
  {
    if(message!="")
    {//if data is available
      Serial.println(message); //show the data
      message=""; //clear the data
    }
  }
  delay(5000); //delay
}
