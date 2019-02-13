#ifndef ENGINE_H
#define ENGINE_H

using namespace std;

class Engine {
	protected:
		bool on;

	public:
		Engine ();

		bool isOn ();
		void setOn (bool o);
};
#endif
