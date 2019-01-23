from Engine.Engine import Engine
from Engine.Bluetooth import Bluetooth
from Engine.Obdii import Obdii

class EngineHandler:
	def __init__(self):
		self.engine = Engine()
		self.bluetooth = Bluetooth()
		self.obd = Obdii()

		self.bluetooth.setup(Obdii)

	def getEngineStatus(self):
		self.bluetooth.send("x") # ask obdii if engine is on # do we wanna use bluetooth here or obd?
		# where "x" is whatever a bluetooth message should look like
		engineStatus = self.bluetooth.receive()
		# assume somewhere (presumably in Obdii) that the received bluetooth message is interpreted into boolean
		self.engine.setOn(engineStatus)

		return self.engine.isOn()

	def turnEngineOn(self):
		self.bluetooth.send("x")
		# TO DO: for best practices, we should get a response from the obd to confirm that engine is on
		# self.bluetooth.receive()
		
		self.engine.setOn(True)

	def turnEngineOff(self):
		self.bluetooth.send("x")
		self.engine.setOn(False)