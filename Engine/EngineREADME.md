# READ ME
## Engine-Bluetooth Module
This Engine module handles all functions that are related to accessing the engine. In this first iteration of the Drugless Driving product, communication with the Engine is through a Bluetooth On-Board Diagnostics (OBD) Dongle. 

**All Bluetooth-related files are stored here.** In the event that the idea to use Bluetooth is dropped, the engine files will require less rework.

## Components
		|_ engine.ino               -->> effectively the "main" master file used for testing
		  |_ Engine Handler         -->> the gatekeeper to all things engine related
		    |_Engine                -->> virtual representation of the state of the vehicle engine
		      |_ Bluetooth          -->> handles all things Bluetooth related
		        |_ Bluetooth Device -->> virtual representation of the state of a Bluetooth Device
		          |_ OBDii

The theory is that the "main" file will only ever have to see and talk to the Engine Handler. 
- The Engine Handler handles the relations between the user's goals and the commands sent to the Bluetooth, OBDii, and Engine classes.
- The Engine stores any data related to the physical vehicle engine, such as if it is on. 
- The Bluetooth class is a sort of handler of its own. It handles all operations that are Bluetooth-related, such as establish the connection to a Bluetooth device, sending signals, and receiving signals. 
- The Bluetooth class is a parent class to virtually represent any type of Bluetooth device.
- The OBDii class at the moment simply stores the CAN signals that should be sent to the physical OBD dongle. Since the solution currently uses a Bluetooth OBD dongle, the OBDii class is inherits from the Bluetooth Device class. 

## Connection to Arduino
	HC-05/6     Arduino
	 RX     >>   TX->1
	 TX     >>   RX->0
	 GND    >>    GND
	 VCC    >>    5V
	 EN     >>    3.3V

## Testing the Bluetooth Module
### Connection to Arduino
	HC-05/6     Arduino
	 RX     >>     2
	 TX     >>     4
	 GND    >>    GND
	 VCC    >>    5V
	 EN     >>    3.3V
1. Switch the pins for RX and TX to 2 and 4, respectively.
2. Upload the bluetooth_test sketch onto the Arduino. 
3. Open the Serial Monitor from the Arduino IDE.
	* The Baud Rate should be set to 38400.
	* If the module is an **HC-06**, set the line endings to `No line endings`
	* If the module is an **HC-05**, set the line endings to `Both NL & CR`
4. You should see the text: *Type AT commands!*. If not, something is wrong and you need to re-check your set-up.
5. Type *AT* in the Arduino IDE Serial monitor input field and press the _Send_ button. You should see the response: *OK*. Now you are ready to change the module’s settings!
6. Type *AT+VERSION* without spaces in the Arduino IDE Serial monitor input field and press the _Send_ button. You should get a response that will have the module name and version, like: *OKlinvorV1.8*.
7. The module is working as expected!

## Bluetooth Commands
For a list of HC-05 Bluetooth AT Commands, go [here]( https://www.teachmemicro.com/hc-05-bluetooth-command-list/).