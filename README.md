READ ME

Folder Structure
|_ Authorities
|_ Detector
|_ Engine
|_ FacialRecognition
|_ GPS
|_ UI


Some pseudo-code and TO-DO notes
# Camera Handling
# Send signal to camera to take a pic
# Call ValidateFace
# If fail, take another pic and loop
# If success, handle saving the pic


# File Handling
# For now, assume that either a different file or the Arduino will handle saving the image taken by the camera as an accessible file
# For now, assume the saved files will be a jpg
# TO DO: check that both files exist
testTaker = open("testTaker.jpg")
currentDriver = open("currentDriver.jpg")

# Facial Recognition
# TO DO: create a different file handles the validity of the testTaker photo (that there is one and only one face)
# Assume it's called at some point before here

# TO DO: create and call on a different file that handles the validity of the currentDriver photo
# TO DO: identify the faces in each photo
# TO DO: compare the identities
# Compare function should use try...except