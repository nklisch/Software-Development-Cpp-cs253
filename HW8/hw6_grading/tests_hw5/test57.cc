#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <sstream>

// output all
using namespace std;

int main() {
    std::cout << "\n\nTEST 57 test57ShowotherFalse" <<endl;
    Enemy testread("iamkey1");
    ifstream yourenemies("goodpony");
    testread.read(yourenemies);
    testread.show_other(false);
    testread.write(std::cout);
}
