import Bluetooth, Obdii

class EngineHandling:
	def __init__(self):
		print("engineHandling init is empty")
		self.engine = False
		self.bluetooth = Bluetooth.__init__()
		self.obd = Obdii.__init__()

		