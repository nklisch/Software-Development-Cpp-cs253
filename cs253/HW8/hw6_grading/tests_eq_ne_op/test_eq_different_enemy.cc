#include "Enemy.h"
#include <fstream>
#include <cassert>

int main() {

  std::ifstream ifs("in2", std::ifstream::in);
  Enemy e("keys");
  e.read(ifs);

  Enemy f("keys");
  e.read(ifs);
  
  assert(!(e == f));
  assert(e != f);
}
