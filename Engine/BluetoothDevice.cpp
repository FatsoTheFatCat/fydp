#include "BluetoothDevice.hpp"

BluetoothDevice::BluetoothDevice (void){
  name = "";
  address = "";
}
  
char* BluetoothDevice::getName () {
	return name;
}

void BluetoothDevice::setName (char* n) {
	name = n;
}

char* BluetoothDevice::getAddress () {
  return address;
}

void BluetoothDevice::setAddress (char* a) {
  address = a;
}
