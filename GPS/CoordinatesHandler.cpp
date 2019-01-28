#include "CoordinatesHandler.hpp"

CoordinatesHandler::CoordinatesHandler () {
	coordinates = new Coordinates ();
	gps = Gps ();
}

void CoordinatesHandler::captureCoordinates () {
	// Coordinates c = gps.getCoordinates ();
 Coordinates c = Coordinates ();
	coordinates.append (c);
}

Coordinates* CoordinatesHandler::getAllCoordinates (Coordinates coordinates) {
	return coordinates;
}

Coordinates CoordinatesHandler::getCoordinates (int i) {
	return coordinates [i];
}

Coordinates CoordinatesHandler::getLastCoordinates () {
	return coordinates [sizeof(coordinates) - 1];
}
