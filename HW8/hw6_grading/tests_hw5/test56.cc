#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <sstream>

//
using namespace std;

int main() {
    std::cout << "\n\nTEST 56 test56ShownameMissingArg" <<endl;
    Enemy testread("iamkey1");
    ifstream yourenemies("goodpony");
    testread.read(yourenemies);
    testread.show_name();
    testread.write(std::cout);
}
