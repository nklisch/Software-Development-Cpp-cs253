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

int main() {
   try{
      Gallery g("lorRoles", "lorKeys");
      assert(g);
      assert(g[1]);
      const Enemy &e = g[1];
      Enemy::iterator it1 = e.begin();
      Enemy::iterator it2(it1);
      assert(it1 == it2);
   }
   catch (const exception &e) {
        cerr << "Test 11: Unexpected exception: " << e.what() <<" --failed"<< '\n';
        return 1;
   }
   catch (...) {
        cerr << "Test 11: Caught something, but it’s not a std::exception‽"<< "--failed"<< '\n';
        return 2;
   }
   cout<<"test11: Enemy iterator equals -- passed"<<'\n';
   return 0;
}
