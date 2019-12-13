#include "Enemy.h"
#include <fstream>
#include <cassert>

int main() {

  std::ifstream ifs("in2", std::ifstream::in);
  Enemy e("keys");
  e.read(ifs);

  std::ifstream ifs2("in2", std::ifstream::in);
  Enemy f("keys");
  f.read(ifs2);
  
  assert(e == f);
  assert(!(e != f));
}
