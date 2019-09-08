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

int main(int argc, char *argv[])
{
  Error::program_name = argv[0];

  vector<Enemy> enemyList;
  string line;
  if (argc == 2)
  {
    Error::outputError("Wrong number of arguments", "Need 2 or more arguments, or no arguments");
  }

  if (argc == 1)
  {
    readStdInput(enemyList);
  }
  else
  {
    vector<string> inFiles;
    string keyFile = argv[1];
    for (int i = 2; i < argc; i++)
    {
      inFiles.push_back(argv[i]);
    }
    readFileInput(keyFile, inFiles, enemyList);
  }

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
