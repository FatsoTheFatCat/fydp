#ifndef OBDII_H
#define OBDII_H

#include "BluetoothDevice.hpp"

using namespace std;

class Obdii : public BluetoothDevice {
	private:
		// TO DO: re-evaluate whether defining these is worth it for the deprecated conversion from string to char*
		const char* STATUS_INQUIRY = "statusInquiry";
		const char* OFF_COMMAND = "off";
		const char* ON_COMMAND = "on";

  public:
		char* name;

    Obdii (void);
  	char* getName ();
		char* getStatusInquiry ();
		char* getOffCommand ();
		char* getOnCommand ();
};
#endif
