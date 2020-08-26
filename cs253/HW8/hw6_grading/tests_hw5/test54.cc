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
    Enemy testread("iamkey1");
    ifstream yourenemies("goodpony");
    testread.read(yourenemies);

    string value = testread.field("yooooo");
  }
  catch (const runtime_error &err){
    cout << "test54 passed, runtime_error = " << err.what() <<endl;
  }
}
