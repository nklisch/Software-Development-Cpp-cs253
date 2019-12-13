#include "Enemy.h"
#include <fstream>
#include <cassert>
#include <string>

using namespace std;

int main() {

  std::ifstream ifs("in2", std::ifstream::in);
  
  Enemy e("keys");
  e.read(ifs);

  assert(e["Name"] == "Nagini");
  assert(e["Species"s] == "Snake");
  assert(e["KilledBy"] == "Neville Longbottom");
  assert(e["LinkMaster"s] == "He Who Must Not Be Named");
}
