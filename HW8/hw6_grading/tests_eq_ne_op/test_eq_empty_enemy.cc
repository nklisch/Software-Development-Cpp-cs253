#include "Enemy.h"
#include <cassert>

int main() {
  Enemy e("keys"), f("keys");
  assert(e == f);
  assert(!(e != f));
}
