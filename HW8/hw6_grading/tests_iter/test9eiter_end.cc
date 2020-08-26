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
      Enemy::iterator it = e.end();
      it--;
   }
   catch (const exception &e) {
        cerr << "Test 9: Unexpected exception: " << e.what() <<" --failed"<< '\n';
        return 1;
   }
   catch (...) {
        cerr << "Test 9: Caught something, but it’s not a std::exception‽"<< "--failed"<< '\n';
        return 2;
   }
   cout<<"test9: Enemy iterator end -- passed"<<'\n';
   return 0;
}
