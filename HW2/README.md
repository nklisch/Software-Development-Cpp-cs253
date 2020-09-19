# CS253 HW2: Command-Line Arguments, More Enemies!                
### *This is a direct copy of the assignment requirements from the instructor.*

## Description                

For this assignment, you will improve upon your previous work, adding command-line arguments and line continuation.                 
## Arguments                

The first command-line argument must be a keyword file. It contains a list of valid keywords, one per line.                 

Any remaining arguments are files containing lists of enemies. If no remaining arguments are given, read enemies from standard input, as in the previous assignment.                 
## Sample Runs                

Here are sample runs, where % is my prompt. What you type looks like this. Ignore the indentation.                 

    % cat keys
    Name
    bonehead
    RealName
    Motif
    % cat in1
    Name Catwoman
    RealName Selina Kyle
    Motif Cats



    Name Joker
    Motif         Nutty as
     a bag of
        	    squirrels
    % cat in2
    Name Riddler
    RealName E. Nigma
    % cat in3
    Name
        Penguin
    ActualName Oswald Chesterfield Cobblepot
    Motif Birds, umbrellas
    % cmake .
    … cmake output appears here …
    % make
    … make output appears here …
    % ./hw2 keys in1 in2
    Name     Catwoman
    RealName Selina Kyle
    Motif    Cats

    Name  Joker
    Motif Nutty as a bag of squirrels

    Name     Riddler
    RealName E. Nigma
    % cat in2 | ./hw2 keys
    Name     Riddler
    RealName E. Nigma
    % ./hw2 keys in2 in3
    Name     Riddler
    RealName E. Nigma
    ./hw2: file “in3”: key “ActualName” not in keyfile
    %

## Input Format                

Same as previous assignment, except …                 

A given enemy ends on an empty line, or end of file. That is, an enemy cannot span input files.                 

Lines can now be continued. If a line begins with a space or tab, then it is a continuation of the previous line of the same file. Conceptually, replace the newline of the previous line and the leading spaces or tabs on the next line with a single space.                 
## Output Format                

Same as previous assignment.                 
## Debugging                

If you encounter “STACK FRAME LINK OVERFLOW”, then try this:

    export STACK_FRAME_LINK_OVERRIDE=0861-f88a75ffe0801823a715cf078a1a6901

## Requirements                
    Error messages:
        go to standard error.
        include the program name, no matter how it was compiled.
        include the offending data, if applicable 
    Produce an error message and stop the program if:
        not enough arguments are given
        a file cannot be opened
        a keyword in an enemies file is not in the keywords file
        the key is not alphabetic
        the key or value is missing
        duplicate keys are encountered in an enemy 
    If more than one problem exists, you don’t have to report them all. Produce one error message and stop.
    The output must end with a newline.
        Newlines do not separate lines—newlines terminate lines. 
    Creativity is a wonderful thing, but your output format is not the place for it. Your non-error output should look exactly like the output shown above. You have more leeway in error cases.
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
    The tar file for this assignment must be called: hw2.tar
    It must contain:
        source files (*.cc)
        header files (*.h) (if any)
        CMakeLists.txt 
    These commands must produce the program hw2 (note the dot): 

    cmake .
    make

    At least -Wall must be used every time g++ runs. 

## How to submit your homework:                

    Use web checkin, or Linux checkin: 

    ~cs253/bin/checkin HW2 hw2.tar

## How to receive negative points:                

Turn in someone else’s work.                 