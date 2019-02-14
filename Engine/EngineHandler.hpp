#ifndef ENGINEHANDLER_H
#define ENGINEHANDLER_H

#include "Engine.hpp"
#include "Bluetooth.hpp"
#include "Obdii.hpp"

using namespace std;

class EngineHandler {
	protected:
		Engine *engine;
		Bluetooth *bluetooth;
		Obdii *obd;

	public:
		EngineHandler (SoftwareSerial *BLEserial);
		bool getEngineStatus ();
		void turnEngineOn ();
		void turnEngineOff ();
};
#endif
