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
    Gallery g("file1","file0", "badfile");
  }
  catch (const runtime_error &err){
    cout << "test13 passed, runtime_error = " << err.what() <<endl;
  }
}
