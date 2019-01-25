#ifndef BLUETOOTHDEVICE_H
#define BLUETOOTHDEVICE_H

using namespace std;

class BluetoothDevice {
	protected: 
		char* name;

	public:
    BluetoothDevice (void);

		char* getName ();
		void setName (char* n);
};
#endif
