#include "Bluetooth.hpp"

Bluetooth::Bluetooth (void) {
  connected = false;

  // Set the baud rate
  Serial.begin(9600); 
  // Serial.write("AT+NAME=DruglessDriving"); 
}

void Bluetooth::findAvailableDevices () { // should eventually return list of devices: BluetoothDevice*
  printf("Finding all Bluetooth devices..."); // TO DO: remove all printf lines - take up a lot more memory than it's worth
  // Get list of available Bluetooth devices
  Serial.write("AT+INQ"); //TO DO: refactor all Bluetooth Commands into a separate file as constants
  // Or is it IRQ?
}

BluetoothDevice Bluetooth::findDevice (char* n) {
  printf("Finding Bluetooth device: ");
  printf(n);
  findAvailableDevices ();
  Serial.read(); // check the response of nearby devices for the desired device
	BluetoothDevice bt;
	bt.setName("bt");
	return bt;
}

void Bluetooth::connectToDevice (BluetoothDevice d) { // should eventually return a bool response to indicate success
  if (connected) {
    // disconnect or fail to connect
  }
  printf("Connecting to Bluetooth device: ");
  printf(d.getName());
	// try...except
	device = d;
  Serial.write(strcat("AT+LINK=",device.getAddress()));
	connected = true;
  // char* response = Serial.read(); // OK or FAIL
}

void Bluetooth::pairDevice (BluetoothDevice d) { // TO DO: figure out if this is necessary
  // Serial.write("AT+PAIR=<Param1>,<Param2>");
}

// it makes sense to setup the Bluetooth to a BluetoothDevice 
// but if this is the only method exposed as public
// then it should take a name as the param
void Bluetooth::setup (BluetoothDevice d) { // TO DO: figure out if separate functions for all these commands are necessary or if they can go in this same setup method
  // Definitely thinking that they should stay as separate functions even if they're going to 1 line functions
  // I'm foreseeing the need to tight pole to "multi-task" during the setup/wake up phase of the car
  // In that case, the main file/function is the one doing the tight polling and it'll only work if the functions are separated
	char* name = d.getName(); 
  printf(name);
  //Check for available nearby devices AT+IRQ or AT+INQ
  Serial.write("AT+IRQ");
  // will we have to pair the device?
  // Serial.write("AT+PAIR=<Param1>,<Param2>");
  // will we have to check the pin?
  // Serial.write("AT+PSWD=<Param>");
  
  //Check the response to check is the desired device is enlisted in the nearby devices
  while(!Serial.available()) {}; // this will have to be moved out of here for sure... it'll cause lag issues
  Serial.read();
  device = d; // save the device

  char* response = "";
  while (!connected) {
    //If device is enlisted, use AT+BIND=<Bluetooth address> to connect to the other device
    // assuming address is set somewhere above here in the 
    Serial.write(strcat("AT+BIND=",d.getAddress()));
  
    //Check the response of the AT+STATE? command until you receive “CONNECTED” (you can go for a while loop here)
    Serial.write("AT+STATE");
    while (!Serial.available()) {}; //this will have to be moved out of here for sure... it'll cause lag issues
    response = Serial.read();
    if (String(response).compareTo("CONNECTED")) {
      connected = true;
    }
  }
  //-------------

	device = findDevice(name);
	// also going to need some tight polling here
	// while (!connected)
	connectToDevice(device);
}

void Bluetooth::send (char* c) {
	Serial.write("")
  printf("Sending Bluetooth command: ");
  printf(c);
}

// eventually this will not be a bool but what will it be?
// I suspect since the Serial.read returns a string that this will be a string
bool Bluetooth::receive () {
	// going to need to do some tight polling here
	// or somewhere else... probably in main
	if(Serial.available()) {
		response = Serial.read()
    return true;
	}
	// call on device to interpret the response
	// return reponse
  printf("Waiting on Bluetooth response: ");
  return false;
}
