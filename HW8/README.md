# CS253 HW8 
### *This is a direct copy of the assignment requirements from the instructor.*
               
## Description                

Like HW7, but with the addition of a race.                 

You can think of this as a chance to correct any mistakes that you made with HW7. If your program is perfect, but slow, you get the full four points. Fast programs can earn some extra points:                 

    top 25%: one extra point
    top 5%: two extra points and fame
    fastest program: three extra points, fame, and glory 

The extra points do not build; you only get, at most, one of the three awards.                 

Your program must be absolutely perfect to even participate in the speed competition. That is, it must produce perfect output for the given input, and it must not break any of the other rules (no warnings, no memory leaks, no decimal ASCII constants, etc.). It’s easy to write a fast program if it fails to meet the specification!                 
Speed Test                

    We will create libhw8.a via cmake & make, as usual.
    We will compile our test program like this: g++ -O3 -Wall test.cc libhw8.a
        We will not add any additional libraries or compiler flags. 
    We will run your code on a quiet system.
    We will run your code with a test program which will not be revealed before the assignment is due.
    The real time (as opposed to the CPU time) will be measured.
    We will run the program three times, and take the minimum time. 

## Debugging                

If you encounter “STACK FRAME LINK OVERFLOW”, then try this:

    export STACK_FRAME_LINK_OVERRIDE=0861-f88a75ffe0801823a715cf078a1a6901

## Requirements                

Same as HW7, except that the library is called libhw8.a.                 
## How to submit your homework:                

    Use web checkin, or Linux checkin: 

    ~cs253/bin/checkin HW8 hw8.tar

## How to receive negative points:                

Turn in someone else’s work.                 