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

// Return index of desired Enemy or -1 if not found.
int find_by_name(const Gallery &g, const string &who) {
for (size_t i=0; i<g.size(); i++)
    if (g[i].field("Name") == who)
    return i;
return -1;          // error
}

void test_enemy_iterators_decrement(const Gallery &g) {
    // Find an Enemy in this Gallery with five key/value pairs:
    int index = find_by_name(g,"Frodo Baggins");
    const Enemy &e = g[index];
    assert(e.size() == 6);

    Enemy::iterator it1 = e.begin();
    auto a1 = it1++;            // iterator “pointing” to first element
    auto b1 = it1++;            // iterator “pointing” to second element
    auto c1 = it1++;            // iterator “pointing” to third element
    auto d1 = it1++;            // iterator “pointing” to forth element

    Enemy::iterator it2 = e.begin();
    const auto a2 = it2;        // iterator “pointing” to first element
    const auto b2 = ++it2;      // iterator “pointing” to second element
    const auto c2 = ++it2;      // iterator “pointing” to third element
    const auto d2 = ++it2;      // iterator “pointing” to fouth element

    Enemy::iterator it3 = e.end();
    it3--;--it3;
    const auto d3 = --it3;      // iterator “pointing” to fourth element
    const auto c3 = --it3;      // iterator “pointing” to third element
    const auto b3 = --it3;      // iterator “pointing” to second element
    const auto a3 = --it3;      // iterator “pointing” to first element

    Enemy::iterator it4 = e.end();
    --it4; it4--;--it4;
    auto d4 = it4--;              // iterator “pointing” to fourth element
    auto c4 = it4--;            // iterator “pointing” to third element
    auto b4 = it4--;            // iterator “pointing” to second element
    auto a4 = it4;              // iterator “pointing” to first element

    // All three must be distinct.
    assert(a1 != b1);
    assert(a1 != c1);
    assert(b1 != c1);
    assert(c1 != d1);

    // Assure that the iterators, acquired in various ways, match.
    assert(a1 == a2);
    assert(b1 == b2);
    assert(c1 == c2);
    assert(d1 == d2);

    assert(a1 == a3);
    assert(b1 == b3);
    assert(c1 == c3);
    assert(d1 == d3);

    assert(a1 == a4);
    assert(b1 == b4);
    assert(c1 == c4);
    assert(d1 == d4);

    // compare key/value Pairs.
    assert(*a1 != *b1);
    assert(*a1 != *c1);
    assert(*b1 != *c1);
    assert(*b1 != *d1);

    assert(*a1 == *a2);
    assert(*b1 == *b2);
    assert(*c1 == *c2);
    assert(*d1 == *d2);

    assert(*a1 == *a3);
    assert(*b1 == *b3);
    assert(*c1 == *c3);
    assert(*d1 == *d3);

    assert(*a1 == *a4);
    assert(*b1 == *b4);
    assert(*c1 == *c4);
    assert(*d1 == *d4);
}

int main() {
   try{
      Gallery g("lorRoles", "lorKeys");
      assert(g);
      test_enemy_iterators_decrement(g);
   }
   catch (const exception &e) {
        cerr << "Test 14: Unexpected exception: " << e.what() <<" --failed"<< '\n';
        return 1;
   }
   catch (...) {
        cerr << "Test 14: Caught something, but it’s not a std::exception‽"<< "--failed"<< '\n';
        return 2;
   }
   cout<<"test14: Enemy iterator get reference -- passed"<<'\n';
   return 0;
}
