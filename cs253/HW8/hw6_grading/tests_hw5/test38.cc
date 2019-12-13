#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <sstream>

// look at those keys!
using namespace std;

int main() {

  try{
    Enemy testwrongkey1("wrongkey1");
    //Enemy testwrongkey2("wrongkey2");
  }
  catch (const runtime_error &err){
    cout << "test38 passed, runtime_error = " << err.what() <<endl;
  }
}
