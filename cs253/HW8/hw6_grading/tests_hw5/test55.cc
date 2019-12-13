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
    std::cout << "\n\nTEST 55 test55NotShowname" <<endl;
    Enemy testread("iamkey1");
    ifstream yourenemies("goodpony");
    testread.read(yourenemies);
    testread.show_name(false);
    testread.write(std::cout);
}
