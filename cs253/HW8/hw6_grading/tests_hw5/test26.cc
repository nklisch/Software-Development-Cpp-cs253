#include "Gallery.h"
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
    Gallery g("/dev/null","file0");
    assert(g.size() == 0);
    Enemy e("file0");
    ifstream yourenemies("file1");
    e.read(yourenemies);
    g.add(e);
    g.add(e);
    assert(g.size() == 2);
}
