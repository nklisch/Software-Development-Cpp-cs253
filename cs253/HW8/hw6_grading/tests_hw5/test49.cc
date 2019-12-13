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
    Enemy a("iamkey1"), b("iamkey1"), c("iamkey1");
    bool got_a = a.read(yourenemies);
    bool got_b = b.read(yourenemies);
    bool got_c = c.read(yourenemies);

    assert(got_a);
    assert(a.size()==3);

    assert(got_b);
    assert(b.size() == 4);

    assert(!got_c);
}
