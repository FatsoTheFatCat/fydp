#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "BluetoothDevice.hpp"
#include <stdio.h>

using namespace std;

class Bluetooth {
	protected:
		bool connected;
		BluetoothDevice device;

  public:
    Bluetooth (void);
    
  	BluetoothDevice findDevice (char* n);
  	void connectToDevice (BluetoothDevice d);
  	void setup (BluetoothDevice t);
  	void send (char* c);
  	bool receive ();
};
#endif
