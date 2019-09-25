#include "Input.h"

using namespace std;

void readEnemysInput(istream &input, vector<Enemy> &enemyList)
{
  string line;
  while (getline(input, line))
  {
    if (!isBlankLine(line))
      enemyList.push_back(readEnemy(input, line));
  }
}

void readKey(string &line, string &key)
{
  auto index = findFirstBlankChar(line);
  if (index != string::npos)
  {
    key = line.substr(0, index);
    line = line.substr(index, line.length() - 1);
  }
  else
  {
    key = line;
    line.clear();
  }
}

void readstdInput(istream &in, vector<Enemy> &el)
{
  Error::currentInput = "cin";
  readEnemysInput(in, el);
}

void readFileInput(vector<string> &files, vector<Enemy> &enemyList)
{
  ifstream inF;
  for (auto f : files)
  {
    Error::currentInput = f;
    inF.open(f);
    if (!inF.is_open())
      throw Error("This file failed to open ", f);

    readEnemysInput(inF, enemyList);
    inF.close();
  }
}

void readLine(istream &input, string &line, string &value)
{
  while (!isspace(line[0]) && input)
  {
    if (value.empty())
      value = trim(line);
    else
      value += " " + trim(line);
    getline(input, line);
  }
}

void readKeyFile(ifstream &input, Keys &k)
{
  string key;
  string line;
  while (getline(input, line))
  {
    key = trim(line);
    if (!line.empty())
      k.add(key);
  }
}

Enemy readEnemy(istream &input, string &line)
{
  string key;
  string value;
  Enemy newEnemy;
  if (isspace(line[0]))
    throw Error("The key is missing for this line", line);

  while (input && !isBlankLine(line))
  {
    readKey(line, key);
    readLine(input, line, value);
    newEnemy.add(key, value);
  }

  if (!newEnemy.hasName())
    throw Error("The enemy is missing it's name", newEnemy.toString());

  return newEnemy;
}