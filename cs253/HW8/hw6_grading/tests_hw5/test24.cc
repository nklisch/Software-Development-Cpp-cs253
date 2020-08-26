#include "Gallery.h"
#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <sstream>

// 
using namespace std;

int main() {
  try{
    Gallery g("/dev/null","file0");
    assert(g.size() == 0);
    g.read("filedoesnotexists","file0");
  }
  catch (const runtime_error &err){
    cout << "test24 passed, runtime_error = " << err.what() <<endl;
  }
}
