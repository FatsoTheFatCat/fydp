from Engine.EngineHandler import EngineHandler
from FacialRecognition.PhotoHandler import PhotoHandler
from GPS.CoordinatesHandler import CoordinatesHandler


# Integration Master File
#	|_GPS
#		|_ Current Location
#		|_ Past 30 Locations Array
#	|_ Camera
#		|_ Take Photo
#		|_ Photo Array
#		|_ Photo Comparison (Image Processing)
#	|_ Bluetooth
#		|_ OBD
#	|_ Alerting Authorities

# While car not started
# 	Make sure on board diagnostics dongle plugged in (call Bluetooth which in turn calls OBD class)
# 	If (person blows into tube)
# 		Take a picture of the person (call the camera class)
# 	Determine if person intoxicated (call sensor)
# 		If yes, Alert authorities and share GPS location (Call authorities file followed by GPS file).
# 		If no, start car


# Initialization
# Set up bluetooth
# handler is commonly associated with event handlers (responds to an action)
# -> instead maybe we can use controller, manager, or modifier
eh = EngineHandler() # this one specifically might be more fitting to call controller
eh.getEngineStatus()
eh.turnEngineOn()
eh.turnEngineOff()
# Arduino initialization stuff


# Camera Handling
# Send signal to camera to take a pic
# Call PhotoHandler to validate
# If fail, take another pic and loop
# If success, handle saving the pic


# File Handling
# For now, assume the saved files will be a jpg
# TO DO: check that both files exist
# testTaker = open("testTaker.jpg")
# currentDriver = open("currentDriver.jpg")


ph = PhotoHandler()
ch = CoordinatesHandler()
