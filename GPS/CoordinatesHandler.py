import Coordinates, Gps

class CoordinatesHandler:
	def __init__(self, gps):
		self.coordinates = coordinates.__init__()[30] #should be an array of 30
		self.gps = gps

	# errr...the intention here is that the handler should be the one to call the GPS to capture the current coordinates
	def captureCoordinates():
		gps.getCoordinates

	def getAllCoordinates(coordinates):
		return self.coordinates

	# get specific coordinate
	def getCoordinates(index):
		return self.coordinates[index]

	def getLastCoordinates():
		return self.coordinates[29] # ???