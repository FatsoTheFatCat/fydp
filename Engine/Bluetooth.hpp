#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "BluetoothDevice.hpp"
#include <stdio.h>

using namespace std;

class Bluetooth {
  protected:
    // Add flags for connected, paired, ready, busy,
    bool connected;
    BluetoothDevice device;
    BluetoothDevice findDevice (char* n);
    bool connectToDevice (BluetoothDevice d);
    void pairDevice (BluetoothDevice d);

  public:
    Bluetooth (void);

    void findAvailableDevices();
    bool setup (char* n);
    void send (char* c);
    char* receive ();
};
#endif
