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
    Gallery g("file2","bond-villains", "gold-odd","file0", "jaws", "file1");
    assert(g.size() == 8);
}
