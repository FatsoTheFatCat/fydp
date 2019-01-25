# READ ME

## Getting Started 
- We're working on Arduino so it's super useful to have the [Arduino IDE](https://www.arduino.cc/en/main/software).
- Arduino can read both C and C++ files. Code in whichever one you're more comfortable with. 
- Clone the repo: `git clone https://github.com/FatsoTheFatCat/fydp.git`.
- Create a new development branch: `git branch -b "name-of-new-branch"`.
	- You may need to set up the reference between your local branch and the remote branch: `git remote add origin https://github.com/user/repo.git`

## Folder Structure
	  |_ Authorities
	  |_ Detector
	  |_ Engine
	      |_ Engine
	      |_ Bluetooth
	      |_ OBDii
	  |_ FacialRecognition
	      |_ Camera
	      |_ Photo
	  |_ GPS
	      |_ Coordinates
	      |_ Gps
	  |_ UI
- **Each module should and will have its own ReadMe. READ IT!**
- The Authorites module will handle all things related to alerting the authorities. (If it makes sense to, the GPS module may get moved into here).
- The Detector module will handle all interfacing with the alcohol/drug detection device. This module will have components such as the control for the vaccum pump and an interpreter for the output of the detector. 
- The Engine module will handle all things related to communicating with the engine. Since we are using a Bluetooth OBDii dongle, all things Bluetooth will also be included here.
- The Facial Recognition module (may get renamed if a better name suits it) includes all the necessary interfacing and handling for facial detection and comparison. This includes the camera interface and all things photo related. 
- The GPS module handles and manipulates all things GPS and location coordinates related. (The GPS module may get moved to the Authorities module if it makes more sense).
- The UI folder contains all user facing interfaces such as the LCD, LEDs, and/or speaker if needed. 