# CS253 HW1: Enemies List                
### *This is a direct copy of the assignment requirements from the instructor.*

## Description                

For this assignment, you will write a C++ program called hw1 that will read data representing an “enemies list” from standard input, and display the entries, properly formatted, to standard output.                 
## Sample Runs                

Here is a sample run, where % is my prompt. What you type looks like this. Ignore the indentation.                 

    % cat data
    Relation boss
    Sin      Fired me without telling me
    When     September 2018

    Title Idiot sister
    Name    Diane
    Sin Accused me of stealing from parents' estate
    When 2012-03-16


    Name    Isaac Newton
    Sin     Lucky enough to be born first and sit under a tree
    When    1666 or so

    Who Benedict Cumberbatch
    Reason ☠$%@★% sets too high a standard!
    % cmake .
    … cmake output appears here …
    % make
    … make output appears here …
    % ./hw1 <data
    Relation boss
    Sin      Fired me without telling me
    When     September 2018

    Title Idiot sister
    Name  Diane
    Sin   Accused me of stealing from parents' estate
    When  2012-03-16

    Name Isaac Newton
    Sin  Lucky enough to be born first and sit under a tree
    When 1666 or so

    Who    Benedict Cumberbatch
    Reason ☠$%@★% sets too high a standard!
    %

### Input Format                

Ignore any trailing tabs or spaces on all lines. An enemy is described by a number of lines, separated by at least one empty line. Each line starts with an alphabetic key, followed by some spaces, followed by a value. Neither the key nor the value may empty.                 
Output Format                

Use the minimum number of spaces (but at least one) between the key and the value such that all the values (of a given enemy) line up in the same column. However, different enemies don’t have to have their values in the same column. Separate multiple enemies by a single empty line. Do not emit tabs, trailing spaces on a line, or trailing blank lines.                 
## Debugging                

If you encounter “STACK FRAME LINK OVERFLOW”, then try this:

    export STACK_FRAME_LINK_OVERRIDE=0861-f88a75ffe0801823a715cf078a1a6901

## Requirements                

    You may assume that each enemy has no more than twenty lines.
    Error messages:
        go to standard error.
        include the program name, no matter how it was compiled.
        include the offending data, if applicable 
    Produce an error message and stop the program if:
        the key is not alphabetic
        the key or value is missing
        duplicate keys are encountered in an enemy 
    The output must end with a newline.
        Newlines do not separate lines—newlines terminate lines. 
    Creativity is a wonderful thing, but your output format is not the place for it. Your output should look exactly like the output shown above.
        UPPERCASE/lowercase matters.
        Spaces matter.
        Blank lines matter.
        Extra output matters. 
    You may not use any external programs via system(), fork(), popen(), exec*(), etc.
    You may not use C-style <stdio.h> or <cstdio> facilities, such as printf(), scanf(), fopen(), and getchar().
        Instead, use C++ facilities such as cout, cerr, and ifstream. 
    You may not use dynamic memory via new, delete, malloc(), calloc(), realloc(), free(), strdup(), etc.
        It’s ok to implicitly use dynamic memory via containers such as string or vector. 
    You may not use the istream::eof() method.
    No global variables.
        Except for an optional single global string containing argv[0]. 
    For readability, don’t use ASCII int constants (65) instead of char constants ('A') for printable characters.
    We will compile your program like this: cmake .; make
        If that generates warnings, you will lose a point.
        If that generates errors, you will lose all points. 
    There is no automated testing/pre-grading/re-grading.
        Test your code yourself. It’s your job.
        Even if you only change it a little bit.
        Even if all you do is add a comment. 

If you have any questions about the requirements, ask. In the real world, your programming tasks will almost always be vague and incompletely specified. Same here.                 
## Tar file                

    For each assignment this semester, you will create a tar file, and turn it in.
    The tar file for this assignment must be called: hw1.tar
    It must contain:
        source files (*.cc)
        header files (*.h) (if any)
        CMakeLists.txt 
    These commands must produce the program hw1 (note the dot): 

    cmake .
    make

    At least -Wall must be used every time g++ runs. 

## How to submit your homework:                

    Use web checkin, or Linux checkin: 

    ~cs253/bin/checkin HW1 hw1.tar

## How to receive negative points:                

Turn in someone else’s work.                 