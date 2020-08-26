#include "Enemy.h"
#include <fstream>
#include <cassert>

int main() {

  std::ifstream ifs("in1", std::ifstream::in);
  
  Enemy e("keys");
  e.read(ifs);
  assert(e);
}
