#include "Enemy.h"
#include <iostream>
#include <cassert>
#include <string>
#include <stdexcept>
#include <utility>

using namespace std;

int main() {

  Enemy e("keys");
  bool errorSent = false;
  size_t idx = 0;

  try {
    pair<string, string> item = e[idx];
  }
  catch (const range_error &err) {
    errorSent = true;
    cout << err.what() <<endl;
  }
  assert(errorSent);
}
