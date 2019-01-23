from GPS.Coordinates import Coordinates

class Gps:
	def __init__(self):
		self.coordinates = Coordinates()
		self.on = True # gotta pick up the part to know if we need indicators for "power"
		self.locating = False # might need tight polling and real time handling (flags)

	def getCoordinates():
		# call on the gps to capture the current coords
		# self.coordinates = Coordinates(0,0)
		return self.coordinates