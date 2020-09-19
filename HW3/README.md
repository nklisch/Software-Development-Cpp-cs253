# CS253 HW3: Options!                
## Description                

For this assignment, you will improve upon your previous work, adding command-line options, and changing a few things.                 
## Arguments                

The first argument is no longer a keyword file. Instead, the first command-line arguments should be options:                 

#### -k keywordfile
    Specify the keyword file. The keyword file contains a list of valid keywords, one per line.
#### -n
    Display lines with Name keys. That is, keys that are exactly the string Name.
#### -l
    Display lines with Link… keys. These are the string Link, followed by an arbitrary alphanumeric string of at least one character, e.g., LinkDog, Link1902689, Linkqq42sv, etc.
#### -o
    Display lines with other keys. That is, keys that aren’t Name or Link… keys. 

If any of -n, -o, or -l are given, then display only lines with those keys. If not, then display all keys.                 
Any remaining arguments are files containing lists of enemies. If no remaining arguments are given, read enemies from standard input, as in the previous assignment.                 
## Input Format                

Same as previous assignment, except that a Name key is mandatory, and keys can now be alphanumeric.                 

As you may have realized, there is no need for an explicit check for alphabetic keys, since the -k keyfile controls which keys are valid.                 
## Output Format                

Same as previous assignment, except that within a given enemy, keys & values are displayed in this order:

    Name
    anything but Name and Link…
    Link…
    Multiple Link… lines are displayed in the input order. 

Except as specified above, the output order is the same as the input order.                 
## Sample Runs                

Here are sample runs, where % is my prompt.                 

    % cat keys
    Name
    Linkage
    LinkIs
    bonehead
    motivation
    RealName
    Motif
    % cat in1
    RealName Victor Von Doom
    Linkage College Acquaintance
    Name Doctor Doom
    motivation Rule the world!
     
     
     
    Name Silver Surfer
    Motif         Really into            
     the whole            
                    silver thing        
    % cat in2
    Name Super-Skrull
    LinkIs Just wants to kill the FF
    RealName Kl'rt
    % cat in3
    Name
        Annihilus
    ActualName unknown
    Origin Negative Zone
    % cmake .
    … cmake output appears here …
    % make
    … make output appears here …
    % ./hw3 -k keys in1 in2
    Name       Doctor Doom
    RealName   Victor Von Doom
    motivation Rule the world!
    Linkage    College Acquaintance
     
    Name  Silver Surfer
    Motif Really into the whole silver thing
     
    Name     Super-Skrull
    RealName Kl'rt
    LinkIs   Just wants to kill the FF
    % ./hw3 -k keys <in3
    ./hw3: key “ActualName” not in keyfile
    % ./hw3 -n -k keys in1 in2
    Name Doctor Doom
     
    Name Silver Surfer
     
    Name Super-Skrull
    % ./hw3 -k keys -ln in1 in2
    Name    Doctor Doom
    Linkage College Acquaintance
     
    Name Silver Surfer
     
    Name   Super-Skrull
    LinkIs Just wants to kill the FF
    % ./hw3 -lkkeys in1 in2
    Linkage College Acquaintance
     
     
    LinkIs Just wants to kill the FF
    %

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
        an options is bad
        a file cannot be opened
        a key in an enemies file is not in the keys file
        the key or value is missing
        duplicate keys are encountered in an enemy
        a Name key is missing from an enemy 
    If more than one problem exists, you don’t have to report them all. Produce one error message and stop.
    -k keyfile option must occur exactly once.
        It doesn’t have to be first.
        The first thing after -k (after optional whitespace) will be the keys file. 
    Options must precede filenames. ./hw3 -k keys foo -n will attempt to process the file -n, which would probably fail.
    Bundling of options must work:
        ./hw3 -ok mykeys data is the same as ./hw3 -o -k mykeys data
        ./hw3 -knewkeys -on data is the same as ./hw3 -k newkeys -o -n data
        ./hw3 -n -lkmykeys data1 dataApN is the same as ./hw3 -n -l -k mykeys data1 dataApN
        ./hw3 -o-k mykeys data is invalid. 
    The -n, -o, and -l options may be specified multiple times, with no additional effect.
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
## Hint                

Use getopt. Seriously, use it. Don’t do this yourself.                 
## Tar file                

    For each assignment this semester, you will create a tar file, and turn it in.
    The tar file for this assignment must be called: hw3.tar
    It must contain:
        source files (*.cc)
        header files (*.h) (if any)
        CMakeLists.txt 
    These commands must produce the program hw3 (note the dot): 

    cmake .
    make

    At least -Wall must be used every time g++ runs. 

## How to submit your homework:                

    Use web checkin, or Linux checkin: 

    ~cs253/bin/checkin HW3 hw3.tar

## How to receive negative points:                

Turn in someone else’s work.                 