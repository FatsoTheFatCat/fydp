#ifndef PHOTOHANDLER_H
#define PHOTOHANDLER_H

#include "Photo.hpp"

class PhotoHandler {
	protected:
		Photo photo;
		bool exists;
		int numFaces;
		bool valid;
	public:
		PhotoHandler ();
		// void identifyFaces
		// sumFaces
		bool getExistence ();
		void validate ();
		bool isValid ();
		bool compare (PhotoHandler other); // PhotoHandler or Photo?
};
#endif
