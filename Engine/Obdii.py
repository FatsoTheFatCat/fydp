from Engine.BluetoothDevice import BluetoothDevice

class Obdii (BluetoothDevice): # inherits/extends BluetoothDevice class
	def __init__(self):
		super()
		self.name = "HH OBD Advanced ELM327"  # or whatever the bluetooth name shows up as