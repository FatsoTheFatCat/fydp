#include "BluetoothDevice.hpp"

BluetoothDevice::BluetoothDevice (void){
  name = "";
}
  
char* BluetoothDevice::getName () {
	return name;
}

void BluetoothDevice::setName (char* n) {
	name = n;
}
