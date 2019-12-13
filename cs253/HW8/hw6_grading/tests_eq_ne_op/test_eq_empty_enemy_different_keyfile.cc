#include "Enemy.h"
#include <cassert>

int main() {
  Enemy e("key"), f("keys");
  assert(e == f);
  assert(!(e != f));
}
