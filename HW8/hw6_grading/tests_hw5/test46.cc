#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <sstream>

// non alphanumeric key
using namespace std;

int main() {
  try{
    Enemy testread("iamkey1");
    ifstream yourenemies("nonAlphkeyEnemy");
    testread.read(yourenemies);
  }
  catch (const runtime_error &err){
    cout << "test46 passed, runtime_error = " << err.what() <<endl;
  }
}
