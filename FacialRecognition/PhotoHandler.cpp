#include "PhotoHandler.hpp"

PhotoHandler::PhotoHandler () {//, photo): //should the handler require a photo to exist already
	photo = Photo ();
	exists = false;
	numFaces = 0;
	valid = false;

	getExistence (); // do I need a "this."
	validate (); // either call this in init or in isValid
}

bool PhotoHandler::getExistence () {
	return exists;
}

void PhotoHandler::validate () {
	// validate that there is one and only one face in the photo
	// TO DO: next step is to separate testTaker (with mouthpiece) and currentDriver (with steering wheel?)
	// the complex facial recognition stuff go here
	valid = false;
}

bool PhotoHandler::isValid () {
	return valid;
}

bool PhotoHandler::compare (PhotoHandler other) {
	// validate the type of the other photo with a try...catch
	// will only compare two valid photos
	if (!valid) {
		return false;
	} else if (!other.valid) {
		return false;
	} else {
		// some of the complex stuff goes here
		// compare if the faces are of the same person
		return false;
		// compare function should use try...catch
	}
}
