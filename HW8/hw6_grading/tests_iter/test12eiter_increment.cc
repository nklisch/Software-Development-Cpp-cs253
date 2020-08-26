#include "Enemy.h"
#include "Gallery.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <sstream>
#include <algorithm>

using namespace std;

void test_enemy_iterators_increment(const Gallery &g) {
    // Find an Enemy in this Gallery with five key/value pairs:
    const Enemy &e = g[1];

    Enemy::iterator it1 = e.begin();
    auto a1 = it1++;            // iterator “pointing” to first element
    auto b1 = it1++;            // iterator “pointing” to second element
    auto c1 = it1++;            // iterator “pointing” to third element

    Enemy::iterator it2 = e.begin();
    const auto a2 = it2;        // iterator “pointing” to first element
    const auto b2 = ++it2;      // iterator “pointing” to second element
    const auto c2 = ++it2;      // iterator “pointing” to third element

    // All three must be distinct.
    assert(a1 != b1);
    assert(a1 != c1);
    assert(b1 != c1);

    // Assure that the iterators, acquired in various ways, match.
    assert(a1 == a2);
    assert(b1 == b2);
    assert(c1 == c2);
}

int main() {
   try{
      Gallery g("lorRoles", "lorKeys");
      assert(g);
      test_enemy_iterators_increment(g);
   }
   catch (const exception &e) {
        cerr << "Test 12: Unexpected exception: " << e.what() <<" --failed"<< '\n';
        return 1;
   }
   catch (...) {
        cerr << "Test 12: Caught something, but it’s not a std::exception‽"<< "--failed"<< '\n';
        return 2;
   }
   cout<<"test12: Enemy iterator increment -- passed"<<'\n';
   return 0;
}
