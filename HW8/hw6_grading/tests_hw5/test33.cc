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
    Gallery g("file1","file0");
    assert(g.size() == 1);
    Enemy *e = g.get(5);
    cout << *e;
  }
  catch (const range_error &err){
    cout << "test33 passed, range_error = " << err.what() <<endl;
  }
}
