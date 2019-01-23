# Purpose of the Engine class is so track the state of the Engine

class Engine:
	def __init__(self):
		self._on = None

	# Derrr...I wanted to be fancy and proper by using the python getter and setter identifiers 
	# but I got infinite recursion instead
	# clearly I'm not a python user

	# @property
	# def _on(self):
	# 	"""Get engine on status"""
	# 	return self._on
	
	# @_on.setter
	# def _on(self, value):
	# 	self._on = value

	def isOn(self):
		return self._on

	def setOn(self, on):
		self._on = on