By: Nathan Klisch
Class: CS370
Homework 3

FileReader: Takes a filename and pipe descriptor an reads the file and stores ther result into the pipe;
Starter: Runs FileReader, parses results into coded values, passes these values into Red, Green and blue. 
Then parses the results and places them into a .pmm file.
Red/Green/Blue: Recieves an array of chars that are numbers in argv, parses them to ints, 
isolates the correct value and writes the result to shared memory.

Questions:
1. Pipe(), read end is index 0, write is index 1
2.  mmap()
3. shm_open(), it returns a file descriptor, which is in an int