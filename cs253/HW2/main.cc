// Nathan Klisch
// cs253, Fall2019
// HW1
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "Error.h"
#include "Input.h"

using namespace std;

int main(int, char *argv[])
{
  Error::program_name = argv[0];

  vector<Enemy> enemyList;
  string line;

  readStdInput(enemyList);

  if (enemyList.empty())
    return 0;

  for (size_t i = 0; i < enemyList.size() - 1; i++)
  {
    enemyList[i].printEnemy();
    cout << '\n';
  }

  enemyList.back().printEnemy();
  return 0;
}
