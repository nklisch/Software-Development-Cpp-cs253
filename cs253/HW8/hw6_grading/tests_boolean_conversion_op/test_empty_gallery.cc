#include "Gallery.h"
#include <cassert>

int main() {

  Gallery g("keys", "in1");
  g.clear();
  assert(!g);
}
