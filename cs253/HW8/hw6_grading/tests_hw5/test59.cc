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
    std::cout << "\n\nTEST 59 test59ShowlinkFalse" <<endl;
    Enemy testread("iamkey1");
    ifstream yourenemies("goodpony");
    testread.read(yourenemies);
    testread.show_link(false);
    testread.write(std::cout);
}
