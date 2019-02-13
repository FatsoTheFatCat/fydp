#include "Obdii.hpp"

// TO DO: re-evaluate whether defining these is worth it for the deprecated conversion from string to char*
#define STATUS_INQUIRY "statusInquiry"
#define OFF_COMMAND "off"
#define ON_COMMAND "on"

// #include "BluetoothDevice.h"
Obdii::Obdii (void) {
  name = "HH OBD Advanced ELM327";  // or whatever the bluetooth name shows up as
}

char* Obdii::getName () {
  return name;
}

// the following methods return the constant CAN signals that are to be sent to the ECU through Bluetooth
char* Obdii::getStatusInquiry () {
	return STATUS_INQUIRY; // the CAN signal required to ask the ECU if the vehicle is on
}

char* Obdii::getOffCommand () {
	return OFF_COMMAND;
}

char* Obdii::getOnCommand () {
	return ON_COMMAND;
}
