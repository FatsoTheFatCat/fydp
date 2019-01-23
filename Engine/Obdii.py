from Engine.BluetoothDevice import BluetoothDevice

class Obdii (BluetoothDevice): # inherits/extends BluetoothDevice class
	def __init__(self):
		super()
		self.name = "HH OBD Advanced ELM327"  # or whatever the bluetooth name shows up as

	# the following methods return the constant CAN signals that are to be sent to the ECU through Bluetooth
	def getStatusInquiry(self):
		return "statusInquiry" # the CAN signal required to ask the ECU if the vehicle is on

	def getOffCommand(self):
		return "off"

	# I'm pretty sure this will never get called but it'll be here if we need it
	# this brings up the worry that we'll be stuck in an infinite loop
	# before we even start testing the user
	# I'm not sure there's a response from the OBD unless the car is on
	# which kind of by-passes our entire project OTL
	def getOnCommand(self):
		return "on"