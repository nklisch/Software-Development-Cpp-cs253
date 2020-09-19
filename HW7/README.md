# CS253 HW7: Iteration! 
### *This is a direct copy of the assignment requirements from the instructor.*               
## Description                

For this assignment, you will build upon your previous work in HW6.                 

Your Gallery class now works with the for (auto v : container) syntax! This implies support for Gallery::begin(), Gallery::end(), and Gallery::iterator. Looping over a Gallery produces read-only references to Enemies, in an unspecified (but complete) order.                 

Similarly, the Enemy class now works with for (auto v : container), so you need Enemy::begin(), Enemy::end(), and Enemy::iterator. Looping over a Enemy produces read-only pairs, containing, in order, the corresponding key & value, much like Enemy[size_t]. The pairs are returned in an unspecified (but complete) order.                 
Methods                
## New Gallery methods                

The following methods & operators must work, where git is of type Gallery::iterator.                 

### Gallery::begin()
    Returns an object of type Gallery::iterator that corresponds to the first Enemy in the Gallery. 

### Gallery::end()
    Returns an object of type Gallery::iterator that corresponds to one past the last Enemy in the Gallery.
    Past, I say! It does not correspond to the last item, since begin() & end() form a half-open interval. 

### ++git
### git++
### --git
### git--
    Increments or decrements the iterator.
    Preincrement/predecrement return the new value, and postincrement/postdecrement return the previous value, in the same manner as ++ and -- work on integers. 

### *git
    Yields a const reference to the Enemy associated with the iterator. 

### git == git
### git != git

    Compares two iterators for equality or inequality.
    Any other comparisons are undefined operations. 

### copy, assignment

    Iterators are copy-constructable, and assignable. 

## New Enemy methods                

The following methods & operators must work, where eit is of type Enemy::iterator.                 

### Enemy::begin()

    Returns an object of type Enemy::iterator that corresponds to the first key,value pair in the Enemy. 

### Enemy::end()

    Returns an object of type Enemy::iterator that corresponds to one past the last key,value pair in the Enemy.
    Past, I say! It does not correspond to the last item, since begin() & end() form a half-open interval. 

### ++eit
### eit++
### --eit
### eit--

        Increments or decrements the iterator.
        Preincrement/predecrement return the new value, and postincrement/postdecrement return the previous value, in the same manner as ++ and -- work on integers. 

### *eit

    Yields the the corresponding pair containing the key,value associated with the iterator. This pair may be returned by value or const reference. 

### eit == eit
### eit != eit
    Compares two iterators for equality or inequality.
    Any other comparisons are undefined operations. 

### copy, assignment
    Iterators are copy-constructable, and assignable. 

Const-correctness is your job for all new methods & operators.                 
Lifetime                

Altering a Gallery or an Enemy potentially invalidates the corresponding iterators.                 
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
     
    add_library(hw7 Enemy.cc Keys.cc Gallery.cc)
    add_executable(test test.cc)
    target_link_libraries(test hw7)
     
    # Create a tar file every time:
    add_custom_target(hw7.tar ALL COMMAND tar cf hw7.tar *.cc *.h CMakeLists.txt)
    % cat oz-villains
     
     
     
    Title    Wicked Witch of the West
    Name     Elphaba
    Where    Winkie Country (west)
    Origin   The Wonderful Wizard of Oz (1900)
    img      https://upload.wikimedia.org/wikipedia/commons/9/93/Wicked_Witch_of_the_West.png
     
    Title    Nome King
    Title2   Gnome King
    Where    Underground
    Name     Roquat the Red
    Name2    Ruggedo
    Origin   Ozma of Oz (1907)
    img      https://upload.wikimedia.org/wikipedia/commons/f/fb/I212.jpg?13895777
     
     
    Name     Mombi
    Title    Wicked Witch of the North
    Where    Gillikin Country (north)
    Origin   The Marvelous Land of Oz (1904)
    img      http://www.oztimeline.net/mombi%20neill%202.gif
     
     
     
     
    % cat oz-keys
    Name
    Name2
    Where
    Title
    Title2
    Origin
    img
    Alias
    % cat test.cc
    #include "Gallery.h"
    #include <algorithm>
    #include <cassert>
    #include <iostream>
    #include <string>
    #include <stdexcept>
     
    using namespace std;
     
    void show(const Enemy e) {          // pass by value to force a copy
        for (auto p : e) {
            assert(e[p.first] == p.second);
            cout << p.first << ": " << p.second << '\n';
        }
    }
     
    void show(const Gallery g) {        // pass by value to force a copy
        string gutter;
        for (const Enemy &e : g) {
            cout << gutter;
            gutter = "\n";
            show(e);
        }
    }
     
    void test_comparison_operators(const Gallery &g) {
        assert(g.size() >= 3);
     
        assert(g[0] == g[0]);
        assert(g[1] == g[1]);
        assert(!(g[1] == g[0]));
        assert(!(g[0] == g[1]));
     
        assert(!(g[0] != g[0]));
        assert(!(g[1] != g[1]));
        assert(g[1] != g[0]);
        assert(g[0] != g[1]);
     
        // Guarantee that all Enemies in this Gallery are distinct.
        assert(g[0] != g[2]);
        assert(g[1] != g[2]);
    }
     
    void test_gallery_iterators(const Gallery &g) {
        Gallery::iterator it1 = g.begin();
        auto a1 = it1++;            // iterator “pointing” to first element
        auto b1 = it1++;            // iterator “pointing” to second element
        auto c1 = it1++;            // iterator “pointing” to third element
     
        Gallery::iterator it2 = g.begin();
        const auto a2 = it2;        // iterator “pointing” to first element
        const auto b2 = ++it2;      // iterator “pointing” to second element
        const auto c2 = ++it2;      // iterator “pointing” to third element
     
        Gallery::iterator it3 = g.end();
        const auto c3 = --it3;      // iterator “pointing” to third element
        const auto b3 = --it3;      // iterator “pointing” to second element
        const auto a3 = --it3;      // iterator “pointing” to first element
     
        Gallery::iterator it4 = g.end();
        it4--;                      // now “points” to third element
        auto c4 = it4--;            // iterator “pointing” to third element
        auto b4 = it4--;            // iterator “pointing” to second element
        auto a4 = it4;              // iterator “pointing” to first element
     
        // All three must be distinct.
        assert(a1 != b1);
        assert(a1 != c1);
        assert(b1 != c1);
     
        // Assure that the iterators, acquired in various ways, match.
        assert(a1 == a2);
        assert(b1 == b2);
        assert(c1 == c2);
     
        assert(a1 == a3);
        assert(b1 == b3);
        assert(c1 == c3);
     
        assert(a1 == a4);
        assert(b1 == b4);
        assert(c1 == c4);
     
        // Instead of comparing iterators, now compare Enemies.
        assert(*a1 != *b1);
        assert(*a1 != *c1);
        assert(*b1 != *c1);
     
        assert(*a1 == *a2);
        assert(*b1 == *b2);
        assert(*c1 == *c2);
     
        assert(*a1 == *a3);
        assert(*b1 == *b3);
        assert(*c1 == *c3);
     
        assert(*a1 == *a4);
        assert(*b1 == *b4);
        assert(*c1 == *c4);
    }
     
    void test_enemy_iterators(const Gallery &g) {
        // Find an Enemy in this Gallery with five key/value pairs:
        const Enemy &e = g[0].size()==5 ? g[0] : g[1];
        assert(e.size() == 5);
     
        Enemy::iterator it1 = e.begin();
        auto a1 = it1++;            // iterator “pointing” to first element
        auto b1 = it1++;            // iterator “pointing” to second element
        auto c1 = it1++;            // iterator “pointing” to third element
     
        Enemy::iterator it2 = e.begin();
        const auto a2 = it2;        // iterator “pointing” to first element
        const auto b2 = ++it2;      // iterator “pointing” to second element
        const auto c2 = ++it2;      // iterator “pointing” to third element
     
        Enemy::iterator it3 = e.end();
        it3--; --it3;               // now “points” to fourth element
        const auto c3 = --it3;      // iterator “pointing” to third element
        const auto b3 = --it3;      // iterator “pointing” to second element
        const auto a3 = --it3;      // iterator “pointing” to first element
     
        Enemy::iterator it4 = e.end();
        --it4; it4--; --it4;        // now “points” to third element
        auto c4 = it4--;            // iterator “pointing” to third element
        auto b4 = it4--;            // iterator “pointing” to second element
        auto a4 = it4;              // iterator “pointing” to first element
     
        // All three must be distinct.
        assert(a1 != b1);
        assert(a1 != c1);
        assert(b1 != c1);
     
        // Assure that the iterators, acquired in various ways, match.
        assert(a1 == a2);
        assert(b1 == b2);
        assert(c1 == c2);
     
        assert(a1 == a3);
        assert(b1 == b3);
        assert(c1 == c3);
     
        assert(a1 == a4);
        assert(b1 == b4);
        assert(c1 == c4);
     
        // Instead of comparing iterators, now compare key/value pairs.
        assert(*a1 != *b1);
        assert(*a1 != *c1);
        assert(*b1 != *c1);
     
        assert(*a1 == *a2);
        assert(*b1 == *b2);
        assert(*c1 == *c2);
     
        assert(*a1 == *a3);
        assert(*b1 == *b3);
        assert(*c1 == *c3);
     
        assert(*a1 == *a4);
        assert(*b1 == *b4);
        assert(*c1 == *c4);
    }
     
    int main() {
        try {
            const Gallery vacant("oz-keys", "/dev/null");
            Gallery monsters("oz-villains", "oz-keys");
     
            assert(!vacant);
            assert(monsters);
            assert(monsters[0]);
     
            test_comparison_operators(monsters);
            test_gallery_iterators(monsters);
            test_enemy_iterators(monsters);
     
            show(vacant);
            show(monsters);
        }
        catch (const exception &e) {
            cerr << "Unexpected exception: " << e.what() << '\n';
            return 1;
        }
        catch (...) {
            cerr << "Caught something, but it’s not a std::exception‽\n";
            return 2;
        }
     
        cout << "*** Done! ***\n";
     
        return 0;
    }
    % cmake .
    … cmake output appears here …
    % make
    … make output appears here …
    [100%] Built target test
    % ./test
    Name: Elphaba
    Origin: The Wonderful Wizard of Oz (1900)
    Title: Wicked Witch of the West
    Where: Winkie Country (west)
    img: https://upload.wikimedia.org/wikipedia/commons/9/93/Wicked_Witch_of_the_West.png
     
    Title2: Gnome King
    Title: Nome King
    Origin: Ozma of Oz (1907)
    Name: Roquat the Red
    Name2: Ruggedo
    Where: Underground
    img: https://upload.wikimedia.org/wikipedia/commons/f/fb/I212.jpg?13895777
     
    Where: Gillikin Country (north)
    Name: Mombi
    Origin: The Marvelous Land of Oz (1904)
    Title: Wicked Witch of the North
    img: http://www.oztimeline.net/mombi%20neill%202.gif
    *** Done! ***

## Requirements                

Same as the previous assignment, given the additional features above.                 
## Tar file                

    The tar file for this assignment must be called: hw7.tar
    It must contain:
        source files (*.cc), including Enemy.cc and Gallery.cc
        header files (*.h), including Enemy.h and Gallery.h
        CMakeLists.txt, which will create the library file libhw7.a. 
    These commands must produce the library libhw7.a: 

    cmake . && make

    Your CMakeLists.txt must use at least -Wall when compiling. 

## How to submit your homework:                

    Use web checkin, or Linux checkin: 

    ~cs253/bin/checkin HW7 hw7.tar

## How to receive negative points:                

Turn in someone else’s work.                 