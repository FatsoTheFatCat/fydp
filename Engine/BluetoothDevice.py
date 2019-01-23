class BluetoothDevice:
	def __init__(self):
		self.name = None

	def setName(self, name):
		self.name = name

	def getName(self):
		return self.name