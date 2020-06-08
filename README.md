# Interactive-Desk-Lights-

This Repo contains the Arduino code used for my Interactive Desk Lights. It is meant to be used with an ESP8266 microcontroller but can be
easily adapted for use with a more common Arduino microcontroller. 

The components needed to replicate this project include a microcontroller (compatible with Arduino IDE),Individually Addressable LEDs,
a 5V power supply (Amperage varies based on the amount of LEDs used), a potentiometer, and a sound detection module. 

The code is organized in the common format that is used within Arduino IDE with global variables and libraries located at the top. Followed
by the intialization of variables in the setup function. And finally, the bulk of the code is located in the loop function. The loop 
function constantly reads the analog output from the potentiometer and based on the value read one of the 3 modes are selected. The first 
mode cycles through all the values in the HSV color spectrum. The second applies a solid color based on the position of the potentiometer. 
The final mode reads the digital output of the sound detection module and based on the volume of the music outputs a design. 
