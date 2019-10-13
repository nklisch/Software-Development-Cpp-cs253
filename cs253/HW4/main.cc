// Nathan Klisch
// cs253, Fall2019
// HW2
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <getopt.h>
#include "Error.h"
#include "Input.h"
#include "Keys.h"
#include "Utilities.h"
#include "Enemy.h"

using namespace std;
struct PrintFlags
{
  bool printName = false, printOthers = false, printLinks = false;
  bool allFalse() const { return !printName && !printOthers && !printLinks; }
  void setAllTrue() { printName = true, printLinks = true, printOthers = true; }
};

void printEnemyList(vector<Enemy> &, PrintFlags flags);
PrintFlags getInput(vector<Enemy> &enemyList, int argc, char *argv[]);
PrintFlags getOptions(const int argc, char *argv[], string &keyfile);

int main(int argc, char *argv[])
{
  vector<Enemy> enemyList;
  PrintFlags flags;
  try
  {
    flags = getInput(enemyList, argc, argv);
  }
  catch (Error e)
  {
    cerr << e;
    return 1;
  }

  printEnemyList(enemyList, flags);

  return 0;
}

PrintFlags getOptions(const int argc, char *argv[], string &keyFile)
{
  PrintFlags flags;

  int option;
  while ((option = getopt(argc, argv, "nlok:")) != -1)
  {
    switch (option)
    {
    case 'n':
      flags.printName = true;
      break;
    case 'l':
      flags.printLinks = true;
      break;
    case 'o':
      flags.printOthers = true;
      break;
    case 'k':
      keyFile = optarg;
      break;
    case '?':
      throw Error("Invalid option given", "");
    default:
      break;
    }
  }
  if (keyFile.empty())
    throw Error("No Key file provided", "Need a Key File");

  if (flags.allFalse())
    flags.setAllTrue();
  return flags;
}

PrintFlags getInput(vector<Enemy> &enemyList, const int argc, char *argv[])
{
  Error::program_name = argv[0];
  string keyFile;
  PrintFlags flags = getOptions(argc, argv, keyFile);
  ifstream inF = ifstream(keyFile);
  Error::currentInput = keyFile;

  if (!inF.is_open())
    throw Error("The key file failed to open ", keyFile);

  readKeyFile(inF, Enemy::validKeys);
  inF.close();

  if (optind >= argc)
    readstdInput(cin, enemyList);
  else
  {
    vector<string> files;
    for (int i = optind; i < argc; i++)
      files.push_back(argv[i]);

    readFileInput(files, enemyList);
  }
  return flags;
}

void printEnemyList(vector<Enemy> &el, PrintFlags flags)
{
  if (el.empty())
    return;

  for (size_t i = 0; i < el.size() - 1; i++)
  {
    el[i].printEnemy(cout, flags.printName, flags.printOthers, flags.printLinks);
    cout << '\n';
  }
  el.back().printEnemy(cout, flags.printName, flags.printOthers, flags.printLinks);
}
