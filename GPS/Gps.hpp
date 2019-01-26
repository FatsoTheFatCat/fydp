#ifndef GPS_H
#define GPS_H

#include "Coordinates.hpp"

class Gps {
	protected:
		Coordinates coordinates;
		bool on;
		bool locating;

	public:
		Coordinates getCoordinates ();
}
#endif
