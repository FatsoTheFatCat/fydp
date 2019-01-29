#ifndef OBDII_H
#define OBDII_H

#include "BluetoothDevice.hpp"

using namespace std;

class Obdii : public BluetoothDevice {
  public:
		char* name;

    Obdii (void);
  	char* getName ();
		char* getStatusInquiry ();
		char* getOffCommand ();
		char* getOnCommand ();
};
#endif
