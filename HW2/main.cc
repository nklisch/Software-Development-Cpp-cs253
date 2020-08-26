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
void getInput(vector<Enemy> &enemyList, int argc, char * argv[]);

int main(int argc, char *argv[])
{
  vector<Enemy> enemyList;

  try{
  getInput(enemyList, argc, argv); 
  }
  catch(Error e)
  {
    e.print();
    return 1;
  } 

  printEnemyList(enemyList);

  return 0;
}

void getInput(vector<Enemy> &enemyList, int argc, char * argv[])
{
  
  Error::program_name = argv[0];

  string line;
  if (argc == 1)
    throw Error("No Key file provided", "Need a Key File");
  
  

  ifstream inF = ifstream(argv[1]);
  Error::currentInput = argv[1];

  if (!inF.is_open())
    throw Error("This key file failed to open ", argv[1]);
  
  Keys validKeys;
  

  readKeyFile(inF, validKeys);
  inF.close();

  vector<string> files;

  for(int i = 2; i < argc; i++)
    files.push_back(argv[i]);
  

  if (argc == 2)
    readstdInput(cin, validKeys, enemyList);
  else
    readFileInput(files, validKeys, enemyList);
    
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


