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
    const Gallery g("bond-villains","file0");
    Gallery h(g);
    assert(g.size() == h.size());
}
