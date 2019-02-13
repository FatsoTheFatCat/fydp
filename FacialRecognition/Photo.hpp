#ifndef PHOTO_H
#define PHOTO_H

using namespace std;

class Photo { // extends built-in file class
  protected:
    char* name;
	public:
		Photo ();
		void setName (char* n);
		char* getName ();
};
#endif
