# PS6: RandWriter

## Contact
Name: Adam Warden
Section: 2 
Time to Complete: 6 hours


## Description
This project is a program that reads in a text file and uses the words to create a random text file. The program takes in a command line argument for the number of words to be generated. The program then reads in the text file and creates a map of all the words and the words that follow them. The program then uses the map to randomly generate a text file of the specified length.

### Features
Markov Model: The program uses a Markov Model to generate the random text file. The program reads in the text file and creates a map of all the words and the words that follow them. The program then uses the map to randomly generate a text file of the specified length.
RandWriter class: The RandWriter class is the main class of the program. It contains the main method and the methods that read in the text file and create the map of words. It also contains the method that generates the random text file.
Tests: Boost tests were used to test the program. The tests were used to test the methods that read in the text file and create the map of words. The tests were also used to test the method that generates the random text file.

### Testing
The program was tested using Boost tests. Each test case is designed to confirm that a specific aspect of the RandWriter class works as expected. If all the test cases pass, it indicates that the methods in the RandWriter class are behaving correctly under various conditions. If any test case fails, it provides information about the specific aspect of the code that needs attention or correction.

### Lambda
I used a lambda expression as a comparator function within the std::sort algorithm. It defines an anonymous function that compares two characters and returns true if the character 'a' is less than the second character 'b'. The lambda function is used tro sort the vector of characters for the Markov Model.

### Issues
One issue I have is that the program does not work with text files that contain words with apostrophes. I tried to fix this issue by adding a condition to the code that checks if the word contains an apostrophe. If it does, the program does not add the word to the map. However, this did not fix the issue. 

### Extra Credit


## Acknowledgements
I received help from Gaurav Bhatanger 
https://github.com/KorfLab/StochHMM
