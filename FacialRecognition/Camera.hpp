#ifndef CAMERA_H
#define CAMERA_H

#include "Photo.hpp"

using namespace std;

class Camera {
	public:
		Camera ();
		bool takePhoto();
		bool storePhoto(Photo p, char* filePath); // this might be done automatically or photo handler might handle this
};
#endif
