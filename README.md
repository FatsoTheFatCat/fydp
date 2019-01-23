# READ ME

## Getting Started 
- Make sure you have [Python](https://www.python.org/downloads/ "Python"). 
	- You can run `python --version` or `py --version` in your console to check if you have it installed.
- We're going to hook it up to Arduino. Presumably info on how to do that is on this [link](https://playground.arduino.cc/interfacing/python "Arduino with Python") - you'll need pyserial to read the serial info from the Arduino, run `python -m pip install pyserial` to install it
- Clone the repo: `git clone https://github.com/FatsoTheFatCat/fydp.git`.
- Create a new development branch: `git branch -b "name-of-new-branch"`.
	- You may need to set up the reference between your local branch and the remote branch: `git remote add origin https://github.com/user/repo.git`

## Folder Structure
	  |_ Authorities
	  |_ Detector
	  |_ Engine
	  		|_ Bluetooth
	  |_ FacialRecognition
	  		|_ Camera
	  		|_ Photo
	  |_ GPS
	  		|_ Coordinates
	  		|_ Gps
	  |_ UI


	Some pseudo-code and TO-DO notes
	Camera Handling
	Send signal to camera to take a pic
	Call ValidateFace
	If fail, take another pic and loop
	If success, handle saving the pic


	File Handling
	For now, assume that either a different file or the Arduino will handle saving the image taken by the camera as an accessible file
	For now, assume the saved files will be a jpg
	TO DO: check that both files exist
	testTaker = open("testTaker.jpg")
	currentDriver = open("currentDriver.jpg")

	Facial Recognition
	TO DO: create a different file handles the validity of the testTaker photo (that there is one and only one face)
	Assume it's called at some point before here

	TO DO: create and call on a different file that handles the validity of the currentDriver photo
	TO DO: identify the faces in each photo
	TO DO: compare the identities
	Compare function should use try...except