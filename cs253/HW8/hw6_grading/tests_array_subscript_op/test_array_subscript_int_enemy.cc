#include "Enemy.h"
#include <fstream>
#include <cassert>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {

  ifstream ifs("in2", ifstream::in);
  
  Enemy e("keys");
  e.read(ifs);

  vector<pair<string, string>> expected = {
      {"Name", "Nagini"},
      {"Species", "Snake"},
      {"KilledBy", "Neville Longbottom"},
      {"LinkMaster", "He Who Must Not Be Named"}
  };
  
  for (unsigned int i = 0; i < e.size(); i++) {
      bool isFound = false;
      for (unsigned int j = 0; j < expected.size(); j++) {
          isFound = isFound || (e[i] == expected[j]);
      }
      assert(isFound);
  }
}
