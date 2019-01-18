import Led, Lcd

class Ui:
	def __init__(self):
		self.lcd = Lcd.__init__()
		self.green = Led.__init__()
		self.red = Led.__init__()
