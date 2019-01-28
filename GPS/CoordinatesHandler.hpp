#ifndef COORDINATES_HANDLER_H
#define COORDINATES_HANDLER_H

#include "Coordinates.hpp"
#include "Gps.hpp"

using namespace std;

class CoordinatesHandler {
	protected:
		Coordinates* coordinates;
		Gps gps;
	public:
		CoordinatesHandler ();
		void captureCoordinates ();
		Coordinates* getAllCoordinates ();
		Coordinates getCoordinates (int i);
		Coordinates getLastCoordinates ();
};
#endif
