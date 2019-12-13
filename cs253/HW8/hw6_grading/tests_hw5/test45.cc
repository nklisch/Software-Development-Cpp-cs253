#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <sstream>

// no match key
using namespace std;

int main() {
  try{
    Enemy testread("iamkey1");
    ifstream yourenemies("readNoMatchEnemy");
    testread.read(yourenemies);
  }
  catch (const runtime_error &err){
    cout << "test9 passed, runtime_error = " << err.what() <<endl;
  }
}
