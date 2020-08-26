#include "Gallery.h"
#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <utility>

using namespace std;

int main() {

    Gallery g("keys", "in1", "in2");

    bool errorSent = false;
    size_t idx = g.size();

    try {
        cout << g[idx];
    }
  catch (const range_error &err) {
    errorSent = true;
    cout << err.what() <<endl;
  }
  assert(errorSent);
}
