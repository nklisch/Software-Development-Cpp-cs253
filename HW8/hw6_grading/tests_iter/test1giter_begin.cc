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
      Gallery::iterator it = g.begin();
      assert(!(*it)["Name"].empty());
   }
   catch (const exception &e) {
        cerr << "Test 1: Unexpected exception: " << e.what() <<" --failed"<< '\n';
        return 1;
   }
   catch (...) {
        cerr << "Test 1: Caught something, but it’s not a std::exception‽"<< "--failed"<< '\n';
        return 2;
   }
   cout<<"test1: Gallery::begin-- passed"<<'\n';
   return 0;
}
