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
    Enemy testread("iamkey1");
    ifstream yourenemies("goodpony");
    assert(testread.read(yourenemies));
}
