#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <sstream>

// output non-Name non-Link...
using namespace std;

int main() {
    std::cout << "\n\nTEST 58 test58ShowotherMissingArg" <<endl;
    Enemy testread("iamkey1");
    ifstream yourenemies("goodpony");
    testread.read(yourenemies);
    testread.show_other();
    testread.write(std::cout);
}
