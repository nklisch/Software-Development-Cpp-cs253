// Nathan Klisch
// cs253, Fall2019
// HW2
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "Error.h"
#include "Input.h"
#include "Keys.h"
#include "Utilities.h"
#include "Enemy.h"

using namespace std;
void printEnemyList(vector<Enemy>&);

int main(int argc, char *argv[])
{
  vector<Enemy> enemyList;
  Error::program_name = argv[0];

  string line;
  if (argc == 1)
  {
    Error("No Key file provided", "Need a Key File").print();
    return 1;
  }
  ifstream inF = ifstream(argv[1]);

  if (!inF.is_open())
  {
    Error("This key file failed to open ", argv[1]).print();
    return 1;
  }
  Keys validKeys;
  Error::currentFile = argv[1];
  try
  {
    validKeys = readKeyFile(inF);
  }
  catch (Error e)
  {
    e.print();
    return 1;
  }
  Error::currentFile = "";
  inF.close();

  if (argc == 1)
  {
    try
    {
      readEnemysFile(cin, validKeys, enemyList);
      printEnemyList(enemyList);
    }
    catch (Error e)
    {
      e.print();
      return 1;
    }
  }
  else
  {

    for (int i = 2; i < argc; i++)
    {
      Error::currentFile = argv[i];
      inF.open(argv[i]);
      if (!inF.is_open())
      {
        throw Error("This file failed to open ", argv[i]);
        return 1;
      }
      try
      {
        readEnemysFile(inF, validKeys, enemyList);
      }
      catch (Error e)
      {
        e.print();
        return 1;
      }
      
      if(i < argc - 1)
        cout << "\n";
      Error::currentFile = "";
      inF.close();
    }
  }

  printEnemyList(enemyList);

  return 0;
}

void printEnemyList(vector<Enemy> &el)
{
  if (el.empty())
    return;

  for (size_t i = 0; i < el.size() - 1; i++)
  {
    el[i].printEnemy();
    cout << '\n';
  }

  el.back().printEnemy();
}
