import Photo

class PhotoHandler:
	# overloads
	# def __init__(self):
	# def __init__(self, name):
	def __init__(self, photo):
		self.photo = photo
		self.exists = False
		self.numFaces = 0
		self.valid = False

		exists()
		validate() # either call this in init or in isValid


	# Private methods
	# identifyFaces
	# sumFaces
	exists():
		self.exists = False

	validate():
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
