# SIT730-Task1.1BlinkName

Simple Morse Code app to blink my name

Consists of a number of function and can lookup the 26 letters of the alphabet to print out the morse code for each letter. space is also supported for multipel words.
An interrupt is used to detect the button press and start/restart the read text function. When the botton is pressed we pull the LED light low and set the is running flag to false read text, dash and dot functions we check if the code should stop running returning to the main loop where the button Pressed check will set the code to run again.
