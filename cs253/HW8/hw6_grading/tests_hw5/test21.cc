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
    g.read("file2","file0");
    assert(g.size() == 1);
}
