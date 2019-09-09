#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <iomanip>
#include "Utilities.h"
#include "Error.h"
#include "Input.h"

using namespace std;

bool readStdInput(vector<Enemy> &enemyList)
{
  string line;
  string key;
  string value;
  skipBlankLines(cin, line);
  while (cin)
  {
    Enemy newEnemy;
    if (!readStdEnemy(newEnemy, line))
      return false;

    if (!newEnemy.empty())
      enemyList.push_back(newEnemy);

    skipBlankLines(cin, line);
  }
  return true;
}

bool readStdEnemy(Enemy &newEnemy, string &line)
{
  do
  {
    string key;
    string value;

    if (isspace(line[0]))
    {
      Error::outputError("The Key is missing on the following line. ", line);
      return false;
    }

    if (!readKey(line, key))
      return false;

    if (!readStdValue(line, value))
    {
      Error::outputError("The value is missing for the following key.", key);
      return false;
    }
    if (!newEnemy.add(key, value))
      return false;

    getline(cin, line);
  } while (!isBlankLine(line));
  return true;
}

bool readStdValue(string &line, string &value)
{
  value = trim(line);
  if (value.empty())
    return false;
  return true;
}

bool readKey(string &line, string &key)
{
  int index = findFirstBlankChar(line);
  if (index > 0)
  {
    key = line.substr(0, index);
    line = line.substr(index, line.length() - 1);
  }
  else
  {
    key = line;
    line.clear();
  }

  if (!isAlphabetic(key))
  {
    Error::outputError("The key is not alphabetic! ", key);
    return false;
  }

  return true;
}

void skipBlankLines(istream &in, string &line)
{
  while (isBlankLine(line) && in)
  {
    getline(in, line);
  }
}

bool readFileInput(string &keyFile, vector<string> &inFiles, vector<Enemy> &enemyList)
{
  vector<string> keys;
  ifstream inF(keyFile);
  if (!inF.is_open())
  {
    Error::outputError("The key file failed to open.", keyFile);
    return false;
  }

  readKeyFile(inF, keys);
  inF.close();

  for (string file : inFiles)
  {
    inF.open(file);
    if (!inF.is_open())
    {
      Error::outputError("The following file failed to open.", keyFile);
      return false;
    }
    if(!readEnemysFile(inF, keys, enemyList))
      return false;
    inF.close();
  }
  return true;
}

bool readEnemysFile(ifstream &inFile, vector<string> &keys, vector<Enemy> &enemyList)
{
  string line;
  while (getline(inFile, line))
  {
    Enemy newEnemy;
    skipBlankLines(inFile, line);
    if (!readEnemyInFile(inFile, line, keys, newEnemy))
      return false;
    enemyList.push_back(newEnemy);
  }
  return true;
}

bool readEnemyInFile(ifstream &inFile, string &line, vector<string> keys, Enemy &newEnemy)
{
  string key;
  string value;
  if (!readInfileKey(line, keys, key))
  {
    Error::outputError("The key on this line is not valid.", line);
    return false;
  }
  value = trim(line);
  if (!getline(inFile, line))
  {
    if (!newEnemy.add(key, value))
      return false;

    return true;
  }

  do
  {
    if (!isspace(line[0]))
    {
      if (key.empty())
      {
        Error::outputError("The key is missing for the following value.", value);
        return false;
      }
      if (value.empty())
      {
        Error::outputError("The value is missing for the following key.", key);
        return false;
      }

      if (!newEnemy.add(key, value))
        return false;

      if (!readInfileKey(line, keys, key))        
        return false;
      
      value = trim(line);
    }
    else
    {
      value += " " + trim(line);
    }

    getline(inFile, line);
  } while (!isBlankLine(line) && inFile);

  if (value.empty())
  {
    Error::outputError("The value is missing for the following key.", key);
    return false;
  }
  if (!newEnemy.add(key, value))
    return false;

  return true;
}

bool readInfileKey(string &line, const vector<string> &keys, string &key)
{
  if (!readKey(line, key))
    return false;

  for (const string k : keys)
  {
    if (k == key)
      return true;
  }
  Error::outputError("The following key is not in the keylist file", key);
  return false;
}

bool readKeyFile(istream &inFile, vector<string> &keys)
{
  string line;
  string key;
  while (getline(inFile, line))
  {
    skipBlankLines(inFile, line);
    //Remove or check for blanks before key?
    if (!readKey(line, key))
      return false;

    keys.push_back(key);
  }
  return true;
}
