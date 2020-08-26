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
      Gallery::iterator it2 = g.begin();
      assert(it1 == it2);
   }
   catch (const exception &e) {
        cerr << "Test 4: Unexpected exception: " << e.what() <<" --failed"<< '\n';
        return 1;
   }
   catch (...) {
        cerr << "Test 4: Caught something, but it’s not a std::exception‽"<< "--failed"<< '\n';
        return 2;
   }
   cout<<"test4: Gallery iterator equals -- passed"<<'\n';
   return 0;
}
