#include "EngineHandler.hpp"

// #include "Engine.h"
// #include "Bluetooth.h"
// #include "Obdii.h"
EngineHandler::EngineHandler (void) {
	engine = Engine ();
	bluetooth = Bluetooth ();
	obd = Obdii ();

	bluetooth.setup (obd);
}

bool EngineHandler::getEngineStatus () {
  char* statusInquiry = obd.getStatusInquiry();
	bluetooth.send (statusInquiry);
	// assumes that bluetooth receive returns a bool for now
	bool engineStatus = bluetooth.receive();
	// assume somewhere (presumably in Obdii) that the received bluetooth message is interpreted into boolean
	engine.setOn (engineStatus);

	return engine.isOn();
}

void EngineHandler::turnEngineOn () {
  char* onCommand = obd.getOnCommand();
	bluetooth.send (onCommand);
	// TO DO: for best practices, we should get a response from the obd to confirm that engine is on
	// bluetooth.receive();
	engine.setOn(true);
}

void EngineHandler::turnEngineOff () {
  char* offCommand = obd.getOffCommand();
	bluetooth.send (offCommand);
	// bluetooth.receive();
	engine.setOn(false);
}
