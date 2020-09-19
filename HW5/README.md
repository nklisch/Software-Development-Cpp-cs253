# CS253 HW5: Two classes: This time it’s classier! 
### *This is a direct copy of the assignment requirements from the instructor.*               
## Description                

Things are going well with class Enemy, but management has decided that you need a class Gallery to hold a collection of enemies. For this assignment, you you will provide:

    Gallery.h, which will contain the interface for class Gallery
    Enemy.h, which will contain the interface for class Enemy
    the library libhw5.a, which will contain the implementation of those classes 

Unfortunately, the Marketing Department, in its zeal, has promised several contradictory constructor interfaces for a Gallery, so you’re stuck with supporting them all—see below.                 
Methods
                
## Gallery must have the following public methods:                

#### Gallery(two to six string filenames)
    Creates a Gallery, and populates it with enemies read from the files given. Each file may contain any number of enemies. One of the files must be a keyfile, but, due to marketing incompetence, it could be any of the given files. You must decide, based on their contents, which file is the keyfile.
    Throw a runtime_error upon no keyfile or too many keyfiles. Throw a runtime_error, with the bad filename, upon a bad file or bad contents.
#### Copy constructor
    Takes another object of the same class, and deep-copies the information, replacing any previous information.
#### Assignment operator
    Takes another object of the same class, and deep-copies the information, replacing any previous information.
#### Destructor
    Destroys this object, including all the enemies associated with it.
#### .read(string filename, string keyfilename)
    Read enemies from this file, using this keyfile, adding them to the Gallery. Throw a runtime_error upon bad file or contents (either file); the object thrown must include the filename
#### .add(Enemy)
    Given an Enemy (not a pointer), add it to this Gallery. The Enemy is copied into the Gallery. Duplicate enemies are fine.
#### .clear()
    Make this Gallery empty.
#### .size()
    Return the number of enemies in this object, as a size_t.
#### .empty()
    Return true iff this object has no entries.
#### .get(size_t n)
    Given a zero-based index, return a pointer to that Enemy. If the index is out of range, throw a range_error, including the erroneous & maximum indices.
    Provide two versions of this method: a const one that returns const Enemy *, and a non-const one that returns Enemy *.
    Like <<, below, the values returned may be in any order, as long as all are represented.
#### ostream << Gallery
    (Not a method.) Write all enemies in this object, with an empty line between enemies. The enemies may be in any order; that is, the first enemy added to the Gallery doesn’t have to be the first enemy written. 

## Enemy must have all the methods and behavior from the previous assignment, plus:                

#### Enemy()
    The default (zero-argument) ctor is no longer required. Therefore, every Enemy must have an associated keyfile.
#### .link(string relation)
    Returns a pointer to a related Enemy from the same Gallery. For example, given an Enemy e that has a line LinkSister Gretel, then e.link("Sister") returns an Enemy * pointing to the Enemy with the Name “Gretel”. Any modification of the associated Gallery may invalidate this pointer.
    If more than one Enemy in the associated Gallery has that Name, then it is unspecified which Enemy is chosen.
    Throw a runtime_error, mentioning the offending name, if this Enemy is not part of a Gallery. Throw a range_error, mentioning the offending name, if this Enemy has no corresponding Link… field, or if no enemy with this Name is found in the associated Gallery. 

Const-correctness, both arguments & methods, is your job. For example, it must be possible to call .size() on a const Gallery, or to pass a const string to .link().                 

You may define other methods, data, or classes, public or private, as you see fit. You may create other source & header files, but we will only #include "Gallery.h" to use a class Gallery, and #include "Enemy.h" to use a class Enemy.                 
## Debugging                

If you encounter “STACK FRAME LINK OVERFLOW”, then try this:

    export STACK_FRAME_LINK_OVERRIDE=0861-f88a75ffe0801823a715cf078a1a6901

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
     
    add_library(hw5 Enemy.cc Keys.cc Gallery.cc)
    add_executable(test test.cc)
    target_link_libraries(test hw5)
     
    # Create a tar file every time:
    add_custom_target(hw5.tar ALL COMMAND tar cf hw5.tar *.cc *.h CMakeLists.txt)
     
    % cat keys
    Name
    Actor
    LinkBoss
    LinkHenchman
    Wealth
    Foobar
    % cat bond-villains
     
    Name Blofeld
    Actor Donald Pleasence
     
     
    Actor Joseph Wiseman
    Name Dr. No
    Wealth $5834849
     
     
    % cat jaws
    Name
                 Jaws
    Actor Richard Kiel
    % cat gold-odd
    Name Goldfinger
    LinkHenchman Oddjob
    Actor Gert Fröbe
     
    LinkBoss Goldfinger
    Name Oddjob
    Actor Harold Sakata
    % cat test.cc
    #include "Gallery.h"
    #include <cassert>
    #include <iostream>
    #include <string>
     
    using namespace std;
     
    int main() {
        Gallery g("bond-villains", "keys", "/dev/null");
        assert(g.size() == 2);
        g.read("jaws", "keys");
        cout << g << "————–————––————–\n";
        assert(g.size() == 3);
        assert(!g.empty());
        g.clear();
        assert(g.size() == 0);
        assert(g.empty());
     
        const Gallery go("keys", "gold-odd");
        for (size_t i=0; i<go.size(); i++) {
            const Enemy *e = go.get(i);
            try {
                const Enemy *h = e->link("Henchman");   // might throw error
                cout << e->field("Name") << "’s henchman is "
                     << h->field("Name") << '\n';
            }
            catch (...) {
                cout << e->field("Name") << "’s boss is "
                     << e->link("Boss")->field("Name") << '\n';
            }
        }
     
        return 0;
    }
    % cmake .
    … cmake output appears here …
    % make
    … make output appears here …
    % ./test
    Name  Blofeld
    Actor Donald Pleasence
     
    Name   Dr. No
    Actor  Joseph Wiseman
    Wealth $5834849
     
    Name  Jaws
    Actor Richard Kiel
    ————–————––————–
    Goldfinger’s henchman is Oddjob
    Oddjob’s boss is Goldfinger

## Hints                

    Two classes that refer to each other can cause problems, because you’re tempted to have each header file #include the other one, which doesn’t work out well. If all that you need is a pointer to the other class, it’s sufficient to do this, outside of any class declaration:
          class Foo; // forward declaration
    Now, you can declare a Foo * without having to #include "Foo.h".
    Most C++ containers, including vector, support assignment and copy ctors. 

## Requirements                
Same as the previous assignment, except:

    Do not put using namespace std; in a header file.
    An empty keyfile is invalid.
    Dynamic memory is allowed, but discouraged.
    You may not have any memory leaks. 

## Tar file                

    The tar file for this assignment must be called: hw5.tar
    It must contain:
        source files (*.cc), including Enemy.cc and Gallery.cc
        header files (*.h), including Enemy.h and Gallery.h
        CMakeLists.txt, which will create the library file libhw5.a. 
    These commands must produce the library libhw5.a: 

    cmake . && make

    Your CMakeLists.txt must use at least -Wall when compiling. 

## How to submit your homework:                

    Use web checkin, or Linux checkin: 

    ~cs253/bin/checkin HW5 hw5.tar

## How to receive negative points:                

Turn in someone else’s work.                 
