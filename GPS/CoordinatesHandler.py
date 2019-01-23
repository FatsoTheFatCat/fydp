from GPS.Coordinates import Coordinates
from GPS.Gps import Gps

class CoordinatesHandler:
	def __init__(self):
		self.coordinates = [] 
		self.gps = Gps()

	# errr...the intention here is that the handler should be the one to call the GPS to capture the current coordinates
	def captureCoordinates():
		#gps.getCoordinates
		newCoord = Coordinates(0,0)
		self.coordinates.append(newCoord)

	def getAllCoordinates(coordinates):
		return self.coordinates

	# get specific coordinate
	def getCoordinates(index):
		return self.coordinates[index]

	def getLastCoordinates():
		lastIndex = len(self.coordinates) - 1
		return self.coordinates[lastIndex]