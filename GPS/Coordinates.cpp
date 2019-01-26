#include "Coordinates.hpp"

Coordinates::Coordinates () {
	latitude = 0;
	longitude = 0;
}

void Coordinates::setLatitude (float lat) {
	latitude = lat;
}

float Coordinates::getLatitude () {
	return latitude;
}

void Coordinates::setLongitude (float lon) {
	longitude = lon;
}

float	Coordinates::getLongitude () {
	return longitude;
}
