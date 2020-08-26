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
    Gallery g("file2","/dev/null", "gold-odd","file0", "jaws", "file1");
    assert(g.size() == 5);
}
