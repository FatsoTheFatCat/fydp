#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "BluetoothDevice.hpp"
#include <stdio.h>
#include <SoftwareSerial.h>

using namespace std;

class Bluetooth {
  protected:
    SoftwareSerial *BLEserial;
    // bool powered, initialized, cModeSet, roleSet, listed, found, paired, binded, connected, busy;
    int flag;
    bool responded, connected;
    BluetoothDevice device;

    bool checkPower ();
    BluetoothDevice* findAvailableDevices ();
    BluetoothDevice findDevice (char* n);
    void pairDevice (BluetoothDevice d);
    bool connectToDevice (BluetoothDevice d);

  public:
    Bluetooth (SoftwareSerial *serial);

    bool setup (char* n);
    void send (char* c);
    char* receive ();
};
#endif
