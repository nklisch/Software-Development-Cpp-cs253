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
      Gallery::iterator it1 = g.begin();
      auto aa = it1;
      Gallery::iterator it2(aa);
      assert((*it2)["where"] == (*aa)["where"]);
   }
   catch (const exception &e) {
        cerr << "Test 3: Unexpected exception: " << e.what() <<" --failed"<< '\n';
        return 1;
   }
   catch (...) {
        cerr << "Test 3: Caught something, but it’s not a std::exception‽"<< "--failed"<< '\n';
        return 2;
   }
   cout<<"test3: Gallery iterator copy and assignment -- passed"<<'\n';
   return 0;
}
