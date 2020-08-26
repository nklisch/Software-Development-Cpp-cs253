#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <utility>

using namespace std;

int main() {

  ifstream ifs("in2", ifstream::in);
  
  Enemy e("keys");
  e.read(ifs);

  bool errorSent = false;
  size_t idx = e.size();

  try {
    pair<string, string> item = e[idx];
  }
  catch (const range_error &err) {
    errorSent = true;
    cout << err.what() <<endl;
  }
  assert(errorSent);
}
