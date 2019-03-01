#include "Obdii.hpp"

Obdii::Obdii (void) {
	// Make and Model: HH OBD Advanced ELM327
  name = "OBDII";
  address = "1D,A5,68988D"; // TO DO: probably best to create a class for BluetoothAddress since the delimiter can be a comma or colon
  deviceClass = "1F00";
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
