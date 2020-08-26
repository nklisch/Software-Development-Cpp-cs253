#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <sstream>

// no Name key
using namespace std;

int main() {
  try{
    Enemy testread("iamkey1");
    ifstream yourenemies("noNamekey");
    testread.read(yourenemies);
  }
  catch (const runtime_error &err){
    cout << "test48 passed, runtime_error = " << err.what() <<endl;
  }
}
