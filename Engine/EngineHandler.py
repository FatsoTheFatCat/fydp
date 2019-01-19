from Engine.Bluetooth import Bluetooth
from Engine.Obdii import Obdii

class EngineHandler:
	def __init__(self):
		self.engine = False
		self.bluetooth = Bluetooth()
		self.obd = Obdii()