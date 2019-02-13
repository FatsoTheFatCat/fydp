#include "Photo.hpp"

Photo::Photo () {// n):
	// name = n;
	// fileType?
	// size?
	// filePath?
}

void Photo::setName (char* n) {
	// TO DO: check for validity of name
	name = n;
}

char* Photo::getName () {
	return name;
}
