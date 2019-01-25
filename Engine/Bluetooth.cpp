#include "Bluetooth.hpp"

// Bluetooth class handles setting up the connection and confirming that the connection is 
// Arduino treats bluetooth as a serial

Bluetooth::Bluetooth (void) {
  connected = false;

  // Serial.begin(9600) // sets the baud rate // not entirely sure this is needed - TBD
}

BluetoothDevice Bluetooth::findDevice (char* n) {
  printf("Finding Bluetooth device: ");
  printf(n);
	BluetoothDevice bt;
	bt.setName("bt");
	return bt;
}

void Bluetooth::connectToDevice (BluetoothDevice d) {
  printf("Connecting to Bluetooth device: ");
  printf(d.getName());
	// try...except
	device = d;
	connected = true;
}

void Bluetooth::setup (BluetoothDevice t) {
	char* name = t.getName();
  printf(name);
	device = findDevice(name);
	// also going to need some tight polling here
	// while (!connected)
	connectToDevice(device);
}

void Bluetooth::send (char* c) {
	// assume to write in Arduino is
	// Serial.Write("")
  printf("Sending Bluetooth command: ");
  printf(c);
}

// eventually this will not be void but what will it be?
bool Bluetooth::receive () {
	// going to need to do some tight polling here
	// or somewhere else... probably in main
	// if(Serial.available())
	//	response = Serial.read()
	// call on device to interpret the response
	// return reponse
  printf("Waiting on Bluetooth response: ");
  return true;
}
