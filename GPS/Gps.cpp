#include "Coordinates.hpp"

Gps::Gps () {
	coordinates = Coordinates ();
	on = true; // gotta pick up the part to know if we need indicators for "power"
	locating = false; // might need tight polling and real time handling (flags)
}

Coordinates Gps::getCoordinates () {
	// call on the gps to capture the current coords
	// coordinates = Coordinates (0,0);
	return coordinates;
}
