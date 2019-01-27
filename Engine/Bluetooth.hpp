#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "BluetoothDevice.hpp"
#include <stdio.h>

using namespace std;

class Bluetooth {
	protected:
		bool connected;
		BluetoothDevice device;
    BluetoothDevice findDevice (char* n);
    void connectToDevice (BluetoothDevice d);
    void pairDevice (BluetoothDevice d);

  public:
    Bluetooth (void);

    void findAvailableDevices();
  	void setup (BluetoothDevice t);
  	void send (char* c);
  	bool receive ();
};
#endif
