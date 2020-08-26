#include "Input.h"

using namespace std;

void readEnemysInput(istream &inFile, Keys &validKeys, vector<Enemy> &enemyList)
{
  string line;
  while (getline(inFile, line))
  {
    if (!isBlankLine(line))
      enemyList.push_back(readEnemy(inFile, line, validKeys));
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

void readstdInput(istream &in, Keys &k, vector<Enemy> &el)
{
  Error::currentInput = "cin";
  readEnemysInput(in, k, el);
}

void readFileInput(vector<string> &files, Keys &validKeys, vector<Enemy> &enemyList)
{
  ifstream inF;
  for (auto f : files)
  {
    Error::currentInput = f;
    inF.open(f);
    if (!inF.is_open())
      throw Error("This file failed to open ", f);

    readEnemysInput(inF, validKeys, enemyList);
    inF.close();
  }
}

Keys readKeyFile(ifstream &inFile, Keys &k)
{
  string key;
  string line;
  while (getline(inFile, line))
  {
    if (!isBlankLine(line))
    {
      readKey(line, key);
      k.add(key);
    }
  }
  return k;
}

Enemy readEnemy(istream &inFile, string &line, Keys &validKeys)
{
  string key;
  string value;
  Enemy newEnemy;
  if (isspace(line[0]))
    throw Error("The key is missing for this line", line);

  readKey(line, key);
  if (!validKeys.contains(key))
    throw Error("This key is not valid, not in provided key file", key);

  value = trim(line);

  if (!getline(inFile, line))
  {
    if (value.empty())
      throw Error("The value is missing for this key", key);
    newEnemy.add(key, value);
  }

  while (!isBlankLine(line) && inFile)
  {
    if (!isspace(line[0]))
    {
      if (value.empty())
        throw Error("The value is missing for this key", key);

      newEnemy.add(key, value);

      readKey(line, key);
      if (!validKeys.contains(key))
        throw Error("This key is not valid, not in provided key file", key);
      
      value = trim(line);
    }
    else
    {
      if (value.empty())
        value = trim(line);
      else
        value += " " + trim(line);
    }

    getline(inFile, line);
  };

  if (value.empty())
    throw Error("The value is missing for this key", key);

  newEnemy.add(key, value);

  return newEnemy;
}