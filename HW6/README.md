# CS253 HW6: Operators! 
### *This is a direct copy of the assignment requirements from the instructor.*
               
## Description                

You will improve on your work in HW5, adding some operators.                 
## Methods                
Enemy must have the following additional public methods & operators:                

#### Enemy[key]
    key can be either a C-style string or a std::string. Return a copy of the value for that key. If the key is not found, throw a range_error, including the bad key.
#### Enemy[size_t]
    Given a zero-based index, return a by value a std::pair containing, in order, the corresponding key & value. If the index is out of range, throw a range_error, including the erroneous & maximum indices.
    A zero argument to [] does not necessarily return the first key/value pair read. The exact order is unspecified, but all pairs must be represented.
#### if (Enemy)
    Succeed if and only if the Enemy is not empty.
#### if (Enemy1 == Enemy2)
    Succeed if and only if the enemies have the same key/value pairs. This must work no matter in what order the key/value pairs were read.
#### if (Enemy1 != Enemy2)
    Same as above, but inequality. 

## Gallery must have the following additional public methods & operators:                

#### Gallery[size_t]
    Given a zero-based index, return a reference to the corresponding Enemy in this Gallery. If the Gallery is const, then return a const reference. If the index is out of range, throw a range_error, including the erroneous & maximum indices.
    A zero argument to [] does not necessarily return the first Enemy read. The exact order is unspecified, but all enemies must be represented.
#### if (Gallery)
    Succeed if and only if the Gallery is not empty. 

You may define other methods, data, or classes, public or private, as you see fit.                 
Debugging                

If you encounter “STACK FRAME LINK OVERFLOW”, then try this:

    export STACK_FRAME_LINK_OVERRIDE=0861-f88a75ffe0801823a715cf078a1a6901

## Sample Run                

This focuses on the features added in this assignment. This does not imply that the previous features are abandoned.                 

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
     
    add_library(hw6 Enemy.cc Keys.cc Gallery.cc)
    add_executable(test test.cc)
    target_link_libraries(test hw6)
     
    # Create a tar file every time:
    add_custom_target(hw6.tar ALL COMMAND tar cf hw6.tar *.cc *.h CMakeLists.txt)
    % cat pokékeys
    Weight
    Height
    Name
    LinkEvolvesFrom
    LinkEvolvesTo
    URL
    % cat pokémon
     
    Name Bulbasaur
    Weight 15.2#
    LinkEvolvesTo Ivysaur
    URL https://www.pokemon.com/us/pokedex/bulbasaur?16713825
     
    Name Ivysaur
    Weight 28.7#
    LinkEvolvesTo Venusaur
    LinkEvolvesFrom Bulbasaur
    URL https://www.pokemon.com/us/pokedex/ivysaur?16713825
     
    Name Venusaur
    Weight 220.5#
    LinkEvolvesFrom Ivysaur
    URL https://www.pokemon.com/us/pokedex/venusaur?16713825
     
    % cat test.cc
    #include "Gallery.h"
    #include <cassert>
    #include <iostream>
    #include <string>
     
    using namespace std;
     
    void show(const Enemy &e) {
        for (size_t i=0; i<e.size(); i++) {
            pair<string,string> p = e[i];
            assert(e[p.first] == p.second);
            cout << p.first << ": " << p.second << '\n';
        }
    }
     
    void show(const Gallery &g) {
        for (size_t i=0; i<g.size(); i++) {
            if (i>0)
                cout << '\n';
            show(g[i]);
        }
    }
     
    int main() {
        Gallery vacant("pokékeys", "/dev/null");
        const Gallery monsters("pokémon", "pokékeys");
     
        assert(!vacant);
        assert(monsters);
        assert(monsters[0]);
     
        assert(monsters[0] == monsters[0]);
        assert(monsters[1] == monsters[1]);
        assert(!(monsters[1] == monsters[0]));
        assert(!(monsters[0] == monsters[1]));
     
        assert(!(monsters[0] != monsters[0]));
        assert(!(monsters[1] != monsters[1]));
        assert(monsters[1] != monsters[0]);
        assert(monsters[0] != monsters[1]);
     
        show(vacant);
        show(monsters);
     
        return 0;
    }
    % cmake .
    … cmake output appears here …
    % make
    … make output appears here …
    % ./test
    LinkEvolvesTo: Ivysaur
    Name: Bulbasaur
    URL: https://www.pokemon.com/us/pokedex/bulbasaur?16713825
    Weight: 15.2#
     
    LinkEvolvesFrom: Bulbasaur
    LinkEvolvesTo: Venusaur
    Name: Ivysaur
    URL: https://www.pokemon.com/us/pokedex/ivysaur?16713825
    Weight: 28.7#
     
    LinkEvolvesFrom: Ivysaur
    Name: Venusaur
    URL: https://www.pokemon.com/us/pokedex/venusaur?16713825
    Weight: 220.5#

## Hints                

Curious how to do the if (Enemy) thing? Read about Conversion Methods at the end of the Struct and Class lecture.                 
## Requirements                

Same as the previous assignment, given the additional features above.                 
## Tar file                

    The tar file for this assignment must be called: hw6.tar
    It must contain:
        source files (*.cc), including Enemy.cc and Gallery.cc
        header files (*.h), including Enemy.h and Gallery.h
        CMakeLists.txt, which will create the library file libhw6.a. 
    These commands must produce the library libhw6.a: 

    cmake . && make

    Your CMakeLists.txt must use at least -Wall when compiling. 

## How to submit your homework:                

    Use web checkin, or Linux checkin: 

    ~cs253/bin/checkin HW6 hw6.tar

## How to receive negative points:                

Turn in someone else’s work.                 
