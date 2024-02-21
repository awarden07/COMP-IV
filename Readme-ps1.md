# PS1: FibLFSR

## Contact
Name: Adam Warden

Section: 2

Time to Complete: 6 hours


## Description
This project creates a fibLFSR class that can be used to encrypt and decrypt messages. The class takes in a seed and a tap position, and then uses those to XOR the bits in the seed to create a new bit. The new bit is then added to the end of the seed, and the first bit is removed. The representation I
used for the register bits is a string of 1s and 0s. The generate function takes in an integer and uses the step function to generate that many bits. The generate function returns a string of bits. The overloaded << operator prints out the seed of the fibLFSR object. The additional unit tests I added were to test the overload operator and constructor.

### Features
The fibLFSR class has the following features:
- A constructor that takes in a seed and a tap position
- a step function that XORs the bits in the seed and returns a new bit
- a generate function that extracts multiple bits from the step function and returns a string of bits 
- destructor that deletes the fibLFSR object
- overloaded << operator that prints out the seed of the fibLFSR object

### Issues
My main issue throughout the project was getting the step function to 
work properly. I had to use a lot of print statements to figure out, 
because my main error was that I was XORing the wrong bits. 

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

### Credits
List where you got any images or other resources.
https://stackoverflow.com/questions/20694616/send-a-variable-to-a-function-and-modify-this-variable-in-c
https://stackoverflow.com/questions/261963/how-can-i-iterate-through-a-string-and-get-an-integer-value-for-each-character
