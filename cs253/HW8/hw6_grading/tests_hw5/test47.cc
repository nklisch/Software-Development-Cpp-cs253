#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <sstream>

// duplicate keys
using namespace std;

int main() {
  try{
    Enemy testread("iamkey1");
    ifstream yourenemies("duplicatekeysEnemy");
    testread.read(yourenemies);
  }
  catch (const runtime_error &err){
    cout << "test47 passed, runtime_error = " << err.what() <<endl;
  }
}
