# PS3: N-Body Simulation

## Contact
Name: Adam Warden
Section: 2
Time to Complete: 3 days


## Description
Explain what the project does.
The purpose of this project is to simulate the motion of objects in a universe, accounting for the gravitational and physical forces mutually affecting each object. The project will take the initial positions and velocities of a set of objects, and simulate their motion over a given period of time. The project will then output the final positions of the objects via a graphical display.

### Features
Describe what your major decisions were and why you did things that way.
There are many member functions in the 'CelestialBody' class to make the objects
more versatile and easier to use. For example, the X and Y positions of the objects can both be set and retrieved using setPositionX/Y and get PositionX/Y.
This also applies for mass and velocity properties of the objects as well.


### Memory
Describe how you managed the lifetimes of your objects, including if you used smart pointers.
The majority of objects, including instances of "CelestialBody," "Universe," and "SpaceSimulation," are allocated on the stack. This indicates that the C++ runtime takes care of managing their lives automatically. These objects' destructors are invoked and their memory is freed when they exit the scope.Typical Containers: The 'SpaceSimulation' and 'Universe' classes both utilize the'std::vector' container to store numerous 'CelestialBody' objects. The'std::vector' itself is responsible for managing the memory for these objects. The vector automatically maintains the memory of the items it contains when it is destroyed or resized.

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.
One issue I had was trying to limit memory leaks. By running Valgrind I noticed that i didnt lose any memory but there was possible lost bytes.

### Extra Credit
Anything special you did.  This is required to earn bonus points.
If you created your own universe file.  Describe it here and explain why it is interesting.
N/A

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
If you used images or other resources than the ones provided, list them here.
Aadit Engineer for the help with the makefile 
