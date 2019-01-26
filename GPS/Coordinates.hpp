#ifndef COORDINATES_H
#define COORDINATES_H

using namespace std;

class Coordinates {
	protected:
		float latitude;
		float longitude;

	public:
		Coordinates ();
		void setLatitude (float lat);
		float getLatitude ();
		void setLongitude (float long);
		float getLongitude ();
}
#endif
