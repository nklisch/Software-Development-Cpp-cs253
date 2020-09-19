# CS253 HW4: Time to get classy!
### *This is a direct copy of the assignment requirements from the instructor.*
                
## Description                

For this assignment, you will convert your HW3 work to a standalone class, called Enemy, which will contain a single enemy. Specifically, you will provide Enemy.h, which will contain the interface of that class, and the library libhw4.a, which will contain the implementation of that class.                 
## Methods                
Enemy must have the following public methods:       
         
### Enemy()
    Create a Enemy containing no key/value pairs. This is an exception to the usual rule of a mandatory Name key.

### Enemy(string keyfile)
    Associate a keyfile with this enemy, for error-checking. The keyfile should contain one alphanumeric key per line. If it doesn’t, or if any other problem with the file or its contents is encountered, throw a runtime_error, mentioning the filename.

### Copy constructor
    Copy all information from another object of the same class.

### Assignment operator
    Copy all information from another object of the same class, replacing any previous information.

### Destructor
    Destroy.

### .read(istream)
    Read an Enemy from istream, replacing any previous information.
    - If a keyfile was provided in the ctor, and any key in the Enemy doesn’t appear in the keyfile, throw a runtime_error, mentioning the bad key.
    - If a non-alphanumeric key is encountered, throw a runtime_error, mentioning the bad key.
    - If duplicate keys are encountered, throw a runtime_error, mentioning the bad key.
    - If no Name key is read, throw a runtime_error.
    - Return true if an enemy was read, false if no enemy found. 

### .write(ostream)
    Write the content of the Enemy to the ostream, as described in Output Format. Don’t add any extra blank lines.
### .write(string filename)
    Write the content of the Enemy to the given file, as described in Output Format. Throw a runtime_error, mentioning the filename, upon failure. Don’t add any extra blank lines.
### .field(string key)
    Return the corresponding value for this key. Throw a range_error mentioning the bad key, if key not found.
### .show_name(bool)
    This concerns keys that are exactly Name. If the argument is true or missing, show Name key/value pairs when writing the Enemy (via .write() or <<). If false, don’t.
### .show_other(bool)
    If the argument is true or missing, show non-Name, non-Link… key/value pairs when writing the Enemy (via .write() or <<). If false, don’t.
### .show_link(bool)
    This concerns keys that start with exactly Link, followed by any number of alphanumeric characters. If the argument is true or missing, show Link… key/value pairs when writing the Enemy (via .write() or <<). If false, don’t.
### .clear()
    Make this Enemy have no key/value pairs.
### .size()
    Return a size_t containing the number of key/value pairs in this Enemy.
### .empty()
    Return true iff Enemy has no key/value pairs. 

## Non-methods:                

### ostream << Enemy
    The << output operator must produce the same output as .write(ostream). 

Const-correctness, for arguments, methods, and operators, is your job. For example, it must be possible to call .size() on a const Enemy, or to pass a const string to .field().                 

You may define other methods or data, public or private, as you see fit. You may define other classes, as you see fit. However, to use the Enemy class, the user need only #include "Enemy.h", not any other header files.                 
Errors                

All errors are indicated by throwing a runtime_error or range_error, as indicated, and must include any offending data: filename, key, etc., as part of the string returned by exception.what().                 
Input Format                

Ignore trailing whitespace on all lines. If a line begins with whitespace, then it is a continuation of the previous line of the same input stream. Conceptually, replace the newline of the previous line and the leading whitespace on the next line with a single space.                 

Ignore any empty lines before an enemy starts. An enemy is described by a number of lines, ending at an empty line or end-of-file. Each line starts with an alphanumeric key, followed by whitespace, followed by a value. Neither the key nor the value may empty.                 
Output Format                

Use the minimum number of spaces (but at least one) between the key and the value such that all the displayed values (of a given enemy) line up in the same column. However, different enemies don’t have to have their values in the same column. Do not emit trailing whitespace on a line. Do not write any blank lines as part of an enemy.                 

Within a given enemy, keys & values are displayed in this order:

    Name
    anything but Name and Link…
    Link…
    Multiple Link… lines are displayed in the input order. 

Except as specified above, the output order is the same as the input order.                 
Debugging                

If you encounter “STACK FRAME LINK OVERFLOW”, then try this:

    export STACK_FRAME_LINK_OVERRIDE=0861-f88a75ffe0801823a715cf078a1a6901

## Libraries                

libhw4.a is a library file. It contains a number of *.o (object) files. It must contain Enemy.o, but it may also contain whatever other *.o files you need. To create a library file:                 

    ar -rcs libhw4.a Enemy.o

To list the contents of an archive:                 

    ar -tv libhw4.a

## Testing                

You will have to write a main() function to test your code. Put it in a separate file, and do not make it part of libhw4.a. Particularly, do not put main() in Enemy.h or Enemy.cc. You will also have to create Enemy.h, and put it into hw4.tar. We will test your program by doing something like this:                 

    mkdir a-new-directory
    cd the-new-directory
    tar -x </some/where/else/hw4.tar
    cmake . && make
    cp /some/other/place/test-program.cc .
    g++ -Wall test-program.cc libhw4.a
    ./a.out

We will supply a main program to do the testing that we want. You should do something similar.                 
## Sample Run                

Here is a sample run, where % is my shell prompt:                 

    % cat CMakeLists.txt
    cmake_minimum_required(VERSION 3.14)
     
    # Using -Wall is required:
    add_compile_options(-Wall)
     
    # These compile flags are highly recommended, but not required:
    add_compile_options(-Wextra -Wpedantic)
     
    # Optional super-strict mode:
    add_compile_options(-fmessage-length=80 -fno-diagnostics-show-option)
    add_compile_options(-fstack-protector-all -g -O3 -std=c++14 -Walloc-zero)
    add_compile_options(-Walloca -Wctor-dtor-privacy -Wduplicated-cond)
    add_compile_options(-Wduplicated-branches -Werror -Wfatal-errors -Winit-self)
    add_compile_options(-Wlogical-op -Wold-style-cast -Wshadow)
    add_compile_options(-Wunused-const-variable=1 -Wzero-as-null-pointer-constant)
     
    # add_compile_options must be BEFORE add_executable or add_library.
     
    add_library(hw4 Enemy.cc Keys.cc)
    add_executable(test test.cc)
    target_link_libraries(test hw4)
     
    # Create a tar file every time:
    add_custom_target(hw4.tar ALL COMMAND tar cf hw4.tar *.cc *.h CMakeLists.txt)
     
    % cat keys
    why
    Name
    Linkage
    BodyType
    LinkURL
    % cat pony-villains
     
     
    BodyType Unicorn
    Linkage Former enemy, now friend
    Name Starlight Glimmer
    why Jealous of Twilight Sparkle
    LinkURL https://mlp.fandom.com/wiki/Starlight_Glimmer?14878817
     
     
    Name Discord       
    BodyType            Chimera       
    Motif         He’s     
     an avatar       
                        of chaos      
    LinkURL
            https://mlp.fandom.com/wiki/Discord
     
     
    % cat test.cc
    #include "Enemy.h"
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cassert>
    #include <stdexcept>
    #include <sstream>
     
    using namespace std;
     
    int main() {
        const Enemy a;
        assert(a.empty());
        assert(a.size() == 0);
     
        ifstream lair("pony-villains");
        assert(lair);
        Enemy b("keys"), c, d;
        bool got_b = b.read(lair);
        bool got_c = c.read(lair);
        bool got_d = d.read(lair);
     
        assert(got_b);
        assert(b.size() == 5);
        assert(!b.empty());
     
        assert(got_c);
        assert(c.size() == 4);
        assert(!c.empty());
     
        assert(!got_d);
     
        cout << b << "————–————––————–\n" << c;
     
        b = c;
        assert(b.size() == 4);
     
        assert(b.field("BodyType"s) == "Chimera");
     
        c.show_other(false);
        cout << "::::::::\n" << c;
        c.show_other();
        c.show_link(false);
        cout << "********\n" << c;
     
        stringstream iss("\n\n\nName \t\v\f xyz  \n\n\n");
        assert(c.read(iss));
        assert(c.size() == 1);
        assert(c.field("Name") == "xyz");
        ostringstream oss;
        assert(oss << c);
        assert(oss.str() == "Name xyz\n");
     
        // Try a field that’s not there:
        try {
            string s = b.field("foobar");
            cerr << "ERROR: .field() worked?\n";
        }
        catch (const range_error &err) {
            cout << "Good, range_error = " << err.what() << '\n';
        }
        catch (const exception &err) {
            cerr << "ERROR: exception = " << err.what() << '\n';
        }
        catch (...) {
            cerr << "ERROR: What the ☆⚡🔪☠§❢💣 did you throw?\n";
        }
     
        return 0;
    }
    % cmake .
    … cmake output appears here …
    % make
    … make output appears here …
    % ./test
    Name     Starlight Glimmer
    BodyType Unicorn
    why      Jealous of Twilight Sparkle
    Linkage  Former enemy, now friend
    LinkURL  https://mlp.fandom.com/wiki/Starlight_Glimmer?14878817
    ————–————––————–
    Name     Discord
    BodyType Chimera
    Motif    He’s an avatar of chaos
    LinkURL  https://mlp.fandom.com/wiki/Discord
    ::::::::
    Name    Discord
    LinkURL https://mlp.fandom.com/wiki/Discord
    ********
    Name     Discord
    BodyType Chimera
    Motif    He’s an avatar of chaos
    Good, range_error = key “foobar” not found

## Hints                

This assignment inherits nothing from previous assignments.
If you use try…catch in your Enemy code, you probably don’t understand exceptions—seek help.
“whitespace” is not just a fancy way of saying “space”. It’s what isspace says it is.
The foolish student will put main() in Enemy.cc, and try to remember to remove it before turning in the homework. Good luck with that. Just put it in a separate file.
.empty() is an adjective, .clear() is a verb.
runtime_error and range_error are different. 

## Requirements                

Behave as if .show_name(true), .show_link(true), and .show_other(true) were all called on a newly-created Enemy.
.field(), .size(), and .empty() are not affected by .show_name(), .show_other(), or .show_link().
In case of a bad .read(), the position of the input stream and the state of the object are unspecified.
You may use the CMakeLists.txt shown, or create your own.
Do not put using namespace std; in any header file.
No method should call exit.
All copies (copy ctor, assignment operator) are “deep”. Do not share data between copies—that’s not making a copy.
You may not use any external programs via system(), fork(), popen(), exec*(), etc.
You may not use C-style <stdio.h> or <cstdio> facilities, such as printf(), scanf(), fopen(), and getchar().
    Instead, use C++ facilities such as cout, cerr, and ifstream. 
You may not use dynamic memory via new, delete, malloc(), calloc(), realloc(), free(), strdup(), etc.
    It’s ok to implicitly use dynamic memory via containers such as string or vector. 
You may not use the istream::eof() method.
No global variables.
For readability, don’t use ASCII int constants (65) instead of char constants ('A') for printable characters.
We will compile your program like this: cmake . && make
    If that generates warnings, you will lose a point.
    If that generates errors, you will lose all points. 
There is no automated testing/pre-grading/re-grading.
    Test your code yourself. It’s your job.
    Even if you only change it a little bit.
    Even if all you do is add a comment. 

If you have any questions about the requirements, ask. In the real world, your programming tasks will almost always be vague and incompletely specified. Same here.                 
## Tar file                

    The tar file for this assignment must be called: hw4.tar
    It must contain:
        source files (*.cc), including Enemy.cc
        header files (*.h), including Enemy.h
        CMakeLists.txt, which will create 
    the library file libhw4.a.
    These commands must produce the library libhw4.a: 

    cmake . && make

    Your CMakeLists.txt must use at least -Wall when compiling. 

## How to submit your homework:                

    Use web checkin, or Linux checkin: 

    ~cs253/bin/checkin HW4 hw4.tar

## How to receive negative points:                

Turn in someone else’s work.                 