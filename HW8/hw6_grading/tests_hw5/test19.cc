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
    Gallery h("bond-villains","file0");
    Gallery g("file1","file0");
    h = g;
    assert(g.size() == h.size());
}
