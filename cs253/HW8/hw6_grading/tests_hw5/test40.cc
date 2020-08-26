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
    ifstream yourenemies("goodpony");
    Enemy enemy1("iamkey1");
    enemy1.read(yourenemies);

    Enemy enemy2(enemy1);
    assert(enemy2.size() == 3);
}
