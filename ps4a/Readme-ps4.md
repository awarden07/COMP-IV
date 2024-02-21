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
drawCell() is a lambda expression that takes the character, x coordinate and y coordinate as parameters and draws the corresponding sprite.

### Issues
I was having a hard time getting the textures to load properly. All textures properly load.

### Extra Credit
I added a clock in the top left corner to keep track of game durations

## Acknowledgements
no external sources used

## Changes
I changed most of the logic behind my functions, including initializing Sokoban, drawing the level, and moving the player. I also added a clock to keep track of game duration.