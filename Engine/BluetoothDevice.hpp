#ifndef BLUETOOTHDEVICE_H
#define BLUETOOTHDEVICE_H

using namespace std;

class BluetoothDevice {
	protected: 
		char* name;
    char* address;

	public:
    BluetoothDevice (void);

		char* getName ();
		void setName (char* n);
    char* getAddress ();
    void setAddress (char* a);
};
#endif
