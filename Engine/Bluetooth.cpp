#include "Bluetooth.hpp"

Bluetooth::Bluetooth (void) {
  connected = false;

  // Set the baud rate to 38400 if in AT command mode
  Serial.begin(38400); 
  Serial.write("AT+NAME=DruglessDriving"); 
}

void Bluetooth::findAvailableDevices () { // should eventually return list of devices: BluetoothDevice*
  printf("Finding all Bluetooth devices..."); // TO DO: remove all printf lines - take up a lot more memory than it's worth
  Serial.write("AT+INQ"); //TO DO: refactor all Bluetooth Commands into a separate file as constants
  // Or is it IRQ?
}

BluetoothDevice Bluetooth::findDevice (char* n) {
  printf("Finding Bluetooth device: ");
  printf(n);
  findAvailableDevices ();
  while(!Serial.available()) {};
  int response = Serial.read(); // check the response of nearby devices for the desired device
	// Interprets the response here
  BluetoothDevice bt = BluetoothDevice();
	bt.setName("bt");
  bt.setAddress("00:00:00:00");
	return bt;
}

bool Bluetooth::connectToDevice (BluetoothDevice d) { 
  int i = 0;
  int response;
  // Attempt to connect to the target device
  // Time-out after 5000ms
  while (!connected && i < 5000) {
    Serial.write(strcat("AT+BIND=",d.getAddress()));
    // hmm or is this supposed to be AT+LINK?
    // if AT+LINK then the response is OK or FAIL
  
    //Check for a connected state
    Serial.write("AT+STATE");
    while (!Serial.available()) {};
    response = Serial.read();
    if (response) { //String(response).compareTo("CONNECTED")) { 
      connected = true;
      return true;
    }
    i++;
  }
  return false;
}

void Bluetooth::pairDevice (BluetoothDevice d) { // TO DO: figure out if this is necessary
  // Serial.write("AT+PAIR=<Param1>,<Param2>");
  // Serial.write("AT+PSWD=<Param>");
}

bool Bluetooth::setup (char* n) { 
  int response;
  
  // Confirm response from command mode
  Serial.write("AT\r\n");
  //if (receive()

  Serial.write("AT+INIT\r\n");
  Serial.write("AT+CMODE=1\r\n"); // might want this to be 0 for a fixed address
  Serial.write("AT+ROLE=1\r\n");
  Serial.write("AT+INQ?\r\n");
  Serial.write(strcat("AT+RNAME?","15,E5,48730\r\n"));
  Serial.write(strcat(strcat("AT+PAIR=","15,E5,48730"),"48\r\n"));
  Serial.write(strcat("AT+BIND=","15,E5,48730\r\n"));
  Serial.write(strcat("AT+LINK=","15,E5,48730\r\n"));
  
  // Check the response for the desired device
  response = receive();
  // interpret response - TO DO after the module arrives
  // if the device can be found in the list
  // TO DO: parse the response for name and address and whatever else
  // Save the device
  device = BluetoothDevice();
  device.setName(n);
  device.setAddress("");
  
  // will we have to pair the device?
  // Serial.write("AT+PAIR=<Param1>,<Param2>");
  // will we have to check the pin?
  // Serial.write("AT+PSWD=<Param>");

  int i = 0;
  // Attempt to connect to the target device
  // Time-out after 5000ms
  while (!connected && i < 5000) {
    Serial.write(strcat("AT+BIND=",device.getAddress()));
  
    //Check for a connected state
    Serial.write("AT+STATE");
    while (!Serial.available()) {};
    response = Serial.read();
    if (String(response).compareTo("CONNECTED")) {
      connected = true;
      return true;
    }
    i++;
  }
  return false;
}

void Bluetooth::send (char* c) {
	Serial.write("");
}

// eventually this will not be a bool but what will it be?
// I suspect since the Serial.read returns an int that this will be an int
char* Bluetooth::receive () {
  char* response = "";
	// going to need to do some tight polling here
	// or somewhere else... probably in main
	if (Serial.available()) {
    while(Serial.available()) { // While there is more to be read, keep reading.
      response += (char)Serial.read();
    }
  }
	// call on device to interpret the response

  return response;
}
