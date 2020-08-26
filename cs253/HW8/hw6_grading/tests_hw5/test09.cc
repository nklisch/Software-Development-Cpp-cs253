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
    Gallery g("fileDoesNotExists","file0");
  }
  catch (const runtime_error &err){
    cout << "test09 passed, runtime_error = " << err.what() <<endl;
  }
}
