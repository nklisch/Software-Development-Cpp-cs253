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

  try {
    string value = e["Name"];
  }
  catch (const range_error &err) {
    errorSent = true;
    cout << err.what() <<endl;
  }
  assert(errorSent);
}
