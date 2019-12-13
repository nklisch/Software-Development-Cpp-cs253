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
    Gallery g("file1","file0");
    assert(g.size() == 1);
    assert(!g.empty());
}
