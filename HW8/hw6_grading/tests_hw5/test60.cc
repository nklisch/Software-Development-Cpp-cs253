#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <sstream>

// output non-Link...
using namespace std;

int main() {
    std::cout << "\n\nTEST 60 test60ShowlinkMissingArg" <<endl;
    Enemy testread("iamkey1");
    ifstream yourenemies("goodpony");
    testread.read(yourenemies);
    testread.show_link();
    testread.write(std::cout);
}
