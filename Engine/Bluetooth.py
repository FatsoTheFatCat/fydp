from Engine.BluetoothDevice import BluetoothDevice

# Bluetooth class handles setting up the connection and confirming that the connection is 
# Arduino treats bluetooth as a serial
class Bluetooth:
	def __init__(self):
		self.connected = False
		self.device = None
		# in the language of Arduino (i.e. C)
		# Serial.begin(9600) # sets the baud rate # not entirely sure this is needed - to be tested

	def findDevice(self, name):
		print("Finding Bluetooth device: '" + name + "'")
		# try...except
		bt = BluetoothDevice()
		bt.setName("bt")
		return bt

	def connectToDevice(self, device):
		print("Connecting to Bluetooth device: '" + device.getName() + "'")
		# try...except
		self.device = device
		self.connected = True

	def setup(self, target):
		name = target.getName()
		print(name)
		device = self.findDevice(name)
		# also going to need some tight polling here
		# while (!self.connected)
		self.connectToDevice(device)

	def send(self, command):
		# assume that writing in the language of Arduino is
		# Serial.Write("")
		print("Sending Bluetooth command: '" + command + "'")

	def receive(self):
		# going to need to do some tight polling here
		# or somewhere else...probably in main
		# in the language of Arduino, 
		# if(Serial.available())
		#		response = Serial.read()
		# call on self.device to interpret the response
		print("Waiting on Bluetooth response")