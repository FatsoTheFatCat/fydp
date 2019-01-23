from Engine.BluetoothDevice import BluetoothDevice

# Bluetooth class handles setting up the connection and confirming that the connection is 
# Arduino treats bluetooth as a serial
class Bluetooth:
	def __init__(self):
		self.connected = False
		# in the language of Arduino (i.e. C)
		# Serial.begin(9600) # sets the baud rate # not entirely sure this is needed - to be tested

	def findDevice(self, name):
		print("Finding Bluetooth device")
		return "device" # will eventually return a BluetoothDevice type

	def connectToDevice(self, device):
		print("Connecting to Bluetooth device")
		# try...except
		self.connected = True

	def setup(self, target):
		name = target.getName
		print(name)
		device = self.findDevice(name)
		# also going to need some tight polling here
		# while (!self.connected)
		self.connectToDevice(device)

	def send(self, command):
		# assume that writing in the language of Arduino is
		# Serial.Write("")
		print("Sending Bluetooth command")

	def receive(self):
		# going to need to do some tight polling here
		# or somewhere else...probably in main
		# in the language of Arduino, 
		# if(Serial.available())
		#		response = Serial.read()
		print("Waiting on Bluetooth response")