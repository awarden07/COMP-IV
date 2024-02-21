# PS2: Hexaflake

## Contact
Name: Adam Warden
Section: 2 
Time to Complete: 1 week


## Description
The goal of this project is to create a recursive program that draws a hexaflake. The hexaflake is a fractal that is created by drawing a hexagon and then drawing a smaller hexagon on each side of the original hexagon. This process is then repeated on each of the smaller hexagons until the desired level of recursion is reached.

### Features
When I decided to implement the recursive calls, I decided to use a for loop to draw the hexagons. This allowed me to draw all of the hexagons in one function call. I also decided to use a variable to keep track of the level of recursion. This allowed me to easily change the number of levels of recursion. My program gets the length of the hexagon and the number of levels of recursion from the user. The program then draws the hexaflake using the user's input. The first step of the recursion is to draw the original hexagon. The next step is to draw the smaller hexagons. This is done by calling the function recursively. The function is called six times, once for each side of the original hexagon. The function is called with the length of the side of the original hexagon divided by 3 and the level of recursion minus 1. The function then draws the smaller hexagon and calls itself again. This process is repeated until the level of recursion is 0. The program then exits.
### Issues
My issue with this program is that I was not able to generate a base hexagon for the hexaflake. The center of the hexaflake is empty because there is something wrong with the organization of me hexagons in my recursive calls, but i do not yet know how to fix the issue.

### Extra Credit


## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

## Late notice
I turned this program in later than usual because myself and my family have been affected by the recent events in the middle east. I have been unable to focus on my school work because of this. I apologize for the late submission.