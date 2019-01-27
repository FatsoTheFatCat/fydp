#include "EngineHandler.hpp"

EngineHandler::EngineHandler (void) {
	engine = Engine ();
	bluetooth = Bluetooth ();
	obd = Obdii ();

	bluetooth.setup (obd);
	// for v1, we'll assume that the product does things sequentially
	// so that the code can just get pumped out
	// i.e all while loops can stay where they are and where they make sense

	// for v2, we can implement the tight polling
	// flags will be needed (we'll make them global in the initial phase)
	// each function will check a flag each time it runs
	// "main" will have a loop that runs through all the functions to simulate the tight polling

	// for v2.5 the flags will be removed from the global scope
	// each module handler will hold the flags as protected members
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
