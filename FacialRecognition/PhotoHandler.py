from FacialRecognition.Photo import Photo

class PhotoHandler:
	def __init__(self): #, photo): #should the handler require a photo to exist already?
		self.photo = Photo()
		self.exists = False
		self.numFaces = 0
		self.valid = False

		self.getExistence()
		self.validate() # either call this in init or in isValid


	# Private methods
	# identifyFaces
	# sumFaces
	def getExistence(self):
		self.exists = False

	def validate(self):
		# validate that there is one and only one face in the photo
		# TO DO: next step is to separate testTaker (with mouthpiece) and currentDriver (with steering wheel?)
		# the complex facial recognition stuff go here
		self.valid = False

	def isValid():
		return self.valid

	def compare(other):
		# validate type of other with try...except
		# will only compare two valid photos
		if self.valid == False:
			return False
		elif other.valid == False:
			return False
		else:
			# some of the complex stuff goes here
			# compare if the faces are of the same person
			return False
			# Compare function should use try...except
			x = "Woo Hoo~"
			try:
				if testTaker == currentDriver:
				  same = True
				else:
					same = False
				print(same)
			except NameError:
			  print("Variables are not defined")
			except:
			  print("Something else went wrong")
