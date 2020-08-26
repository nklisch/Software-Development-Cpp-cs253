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
    Gallery g("bond-villains","file0");
    assert(g.size() == 3);
    g.read("file3","file00");
    assert(g.size() == 4);
}
