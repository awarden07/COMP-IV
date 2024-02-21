# PS2a: Sokoban

## Contact
Name: Adam Warden
Section: 2 
Time to Complete: 3 hours


## Description
This project loads level data from a file and draws it to the screen. The player can move around the level and push boxes. The player wins when all boxes are on the goal tiles. 

### Features
This project includes a Sokoban class that loads level data from a file and stores it in a vector of strings. The Sokoban class also has a draw function that draws the level to the screen. The player can move around the level and push boxes. The player wins when all boxes are on the goal tiles.

### Memory
The Sokoban class stores the level data in a vector of strings. The Sokoban class also stores the player's position in a pair of ints.

### Lambdas
drawObject is a lamda function that takes x and y coordinates and the fill color as parameters. 'std::for_each' is used to iterate through the level data and call drawObject for each character in the level data.

### Issues
Only half of the level seemed to be displayed on the screen which restricted the players movement on the board.

### Extra Credit


## Acknowledgements
no external sources used
