#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <stdexcept>
#include <utility>

using namespace std;

int main() {

  ifstream ifs("in2", ifstream::in);
  
  Enemy e("keys");
  e.read(ifs);

  bool errorSent = false;

  try {
    string value = e["Something"];
  }
  catch (const range_error &err) {
    errorSent = true;
    cout << err.what() <<endl;
  }
  assert(errorSent);
}
