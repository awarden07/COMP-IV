# PS5: DNA Alignment

## Contact
Name: Adam Warden
Section: 2
Time to Complete: 6 hours

Partner:

## Description
This project revolves around the comparison of two genetic sequences and quantifying their similarity. The goal is to determine the degree of similarity between the two sequences, and to do so in a way that is efficient and accurate. This program will take two sequences as input and output the similarity score, the alignment of the two sequences, and the time and memory usage of the program. 
### Features
The EDistance class contains the main method, which is responsible for reading in the two sequences, calling the methods to calculate the similarity score and alignment, and outputting the results. The EDistance class also contains the methods to calculate the similarity score and alignment. The constructor checks if the input only contain valid characters or not. Both 
sequences are extended with a '-' character for insertions/deletions. The optimal alignment calculation used an algorithm that iterates through the matrix of sequences and calculates the minimum edit distance at each cell based on adjacent cells.

### Issues
Instead of using exit(1), i could have provided better error handling for more detailed error messages. I also had trouble eliminating redundancy in optDistance, because I reversed the order of entire sequence and could have been more efficient.

### Extra Credit


## Analysis

### Example
Do one additional test case by hand. It should be constructed in such a way that you know the correct  output before running your program on it, and it should be a "corner case" that helps check if your program handles all special situations correctly. 

Please list:
 - a copy of the test case input
 - the expected test case output
 - whether your program ran correctly on it or not
 - optionally, any other remarks

### Specs
Your Computer
Memory: 16GB
Processors: Ryzen 5 5600X 6-Core Processor

Partner's Computer
Memory: (ex: 8gb, DDR4)
Processors: (ex: i5-8500 @ 3.00 GHz x6)

### Runs
Fill in the table with the results of running your code on both your and your partner's computers.

| data file     | distance | memory (mb) | time (seconds) | partner time |
|---------------|----------|-------------|----------------|--------------|
|ecoli2500.txt  |   118    |     39.3    |    0.24882     |      
|ecoli5000.txt  |   160    |    156.6    |    1.20432     |     
|ecoli10000.txt |   223    |    625.6    |    5.40162     |       
|ecoli20000.txt |   3135   |    2443     |    19.7882     |      
|ecoli50000.txt |          |             |                |      
|ecoli100000.txt|          |             |                |     

Here is an example from another computer for some of the files.

| data file    | distance | time (s) |
|--------------|----------|----------|
|ecoli2500.txt |      118 |    0.171 |
|ecoli5000.txt |      160 |    0.529 |
|ecoli7000.txt |      194 |    0.990 |
|ecoli10000.txt|      223 |    1.972 |
|ecoli20000.txt|     3135 |    7.730 |

### Time
Assume the two strings are the same length (M = N).  By applying the doubling method to the data points that you obtained, estimate the running time of youu program in seconds as a polynomial function of N, in the form a * N^b for some constants a and b.  Determine the largest input your program can handle if it is limited to one day of computation.

Provide a brief justification/explanation of how you applied the doubling method, and if you data seems not to work, describe what went wrong and use the sample data instead.
 - a = 1
 - b = 1.52
 - largest N = 2^28 = 268435456

### Memory
Assume the two strings are the same length (M = N).  Look at your code and determine how much memory it requires as a polynomial function of N, in the form a * N^b for some constants a and b.  Determine the largest input size your computer can handle given the amount of memory available.
 - a = 1
 - b = 2
 - largest N = 131072 bytes


## Pair Programming



## Acknowledgements
Aadit Engineer for assistance with code

## Changes
In my changes, I addressed my valgrind, linting, and testing errors. My test error as well as my valgrind error seemed to go hand in hand. In my optDistance function, I seemed to be calculating the matrix value correctly, but the logic of my loop and indicing was incorrect. I was going out of bounds in my matrix and attempted to access an element that didnt exist. There was a discrepency between the reported cost and calculated cost in my test case too, because of my matrix in optDistance. I fixed this by changing the return statement to show the value at the top left corner of the matrix (optimal distance). I simplified by calculateDifference code by using the ternary condition operator '? :'. I also improved the UI by adding input validation to make sure only valid sequences are entered, as well as formatted the output with newlines for better readability.