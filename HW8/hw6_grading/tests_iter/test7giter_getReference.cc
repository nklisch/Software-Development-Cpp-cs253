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

void test_gallery_iterators(const Gallery &g) {
  Gallery::iterator it1 = g.begin();
  auto a1 = it1++;            // iterator “pointing” to first element
  auto b1 = it1++;            // iterator “pointing” to second element
  auto c1 = it1++;            // iterator “pointing” to third element

  Gallery::iterator it2 = g.begin();
  const auto a2 = it2;        // iterator “pointing” to first element
  const auto b2 = ++it2;      // iterator “pointing” to second element
  const auto c2 = ++it2;      // iterator “pointing” to third element

  Gallery::iterator it3 = g.end();
  const auto c3 = --it3;      // iterator “pointing” to third element
  const auto b3 = --it3;      // iterator “pointing” to second element
  const auto a3 = --it3;      // iterator “pointing” to first element

  Gallery::iterator it4 = g.end();
  it4--;                      // now “points” to third element
  auto c4 = it4--;            // iterator “pointing” to third element
  auto b4 = it4--;            // iterator “pointing” to second element
  auto a4 = it4;              // iterator “pointing” to first element

  assert(a1 == a3);
  assert(b1 == b3);
  assert(c1 == c3);

  assert(a1 == a4);
  assert(b1 == b4);
  assert(c1 == c4);

  assert(*a1 != *b1);
  assert(*a1 != *c1);
  assert(*b1 != *c1);

  assert(*a1 == *a2);
  assert(*b1 == *b2);
  assert(*c1 == *c2);

  assert(*a1 == *a3);
  assert(*b1 == *b3);
  assert(*c1 == *c3);

  assert(*a1 == *a4);
  assert(*b1 == *b4);
  assert(*c1 == *c4);

}

int main() {
   try{
      Gallery g("lorRoles", "lorKeys");
      assert(g);
      test_gallery_iterators(g);
   }
   catch (const exception &e) {
        cerr << "Test 7: Unexpected exception: " << e.what() <<" --failed"<< '\n';
        return 1;
   }
   catch (...) {
        cerr << "Test 7: Caught something, but it’s not a std::exception‽"<< "--failed"<< '\n';
        return 2;
   }
   cout<<"test7: Gallery iterator get reference -- passed"<<'\n';
   return 0;
}
