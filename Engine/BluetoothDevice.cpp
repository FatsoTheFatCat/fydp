#include "BluetoothDevice.hpp"

BluetoothDevice::BluetoothDevice (void){
  name = "";
  address = "";
  deviceClass = "";
  rssiSignalStrength = "";
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

char* BluetoothDevice::getDeviceClass () {
	return deviceClass;
}

void BluetoothDevice::setDeviceClass (char* c) {
	deviceClass = c;
}

char* BluetoothDevice::getRssiSignalStrength () {
	return rssiSignalStrength;
}

void BluetoothDevice::setRssiSignalStrength (char* s) {
	rssiSignalStrength = s;
}
