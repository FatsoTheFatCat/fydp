#ifndef BLUETOOTHDEVICE_H
#define BLUETOOTHDEVICE_H

using namespace std;

class BluetoothDevice {
	protected: 
		char* name;
    char* address;
    char* deviceClass;
    char* rssiSignalStrength;

	public:
    BluetoothDevice (void);

		char* getName ();
		void setName (char* n);
    char* getAddress ();
    void setAddress (char* a);
    char* getDeviceClass ();
    void setDeviceClass (char* c);
    char* getRssiSignalStrength ();
    void setRssiSignalStrength (char* s);
};
#endif
