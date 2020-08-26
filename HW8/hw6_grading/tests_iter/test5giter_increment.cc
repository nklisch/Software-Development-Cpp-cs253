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

void test_gallery_iterators_increment(const Gallery &g) {
    Gallery::iterator it1 = g.begin();
    auto a1 = it1++;            // iterator “pointing” to first element
    auto b1 = it1++;            // iterator “pointing” to second element
    auto c1 = it1++;            // iterator “pointing” to third element

    Gallery::iterator it2 = g.begin();
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
      test_gallery_iterators_increment(g);
   }
   catch (const exception &e) {
        cerr << "Test 5: Unexpected exception: " << e.what() <<" --failed"<< '\n';
        return 1;
   }
   catch (...) {
        cerr << "Test 5: Caught something, but it’s not a std::exception‽"<< "--failed"<< '\n';
        return 2;
   }
   cout<<"test5: Gallery iterator increment -- passed"<<'\n';
   return 0;
}
