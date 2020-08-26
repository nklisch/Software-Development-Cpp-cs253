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
      assert((*it1).second == (*it2).second);
   }
   catch (const exception &e) {
        cerr << "Test 10: Unexpected exception: " << e.what() <<" --failed"<< '\n';
        return 1;
   }
   catch (...) {
        cerr << "Test 10: Caught something, but it’s not a std::exception‽"<< "--failed"<< '\n';
        return 2;
   }
   cout<<"test10: Enemy iterator copy&Assignment -- passed"<<'\n';
   return 0;
}
