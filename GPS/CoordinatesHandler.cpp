#include "CoordinatesHandler.hpp"

CoordinatesHandler::CoordinatesHandler () {
	coordinates = Coordinates [];
	gps = Gps ();
}

CoordinatesHandler::captureCoordinates () {
	// Coordinates c = gps.getCoordinates ();
	coordinates.append (c);
}

CoordinatesHandler::getAllCoordinates (Coordinates coordinates) {
	return coordinates;
}

CoordinatesHandler::getCoordinates (int i) {
	return coordinates [i];
}

CoordinatesHandler::getLastCoordinates () {
	return coordinates [len(coordinates) - 1];
}
