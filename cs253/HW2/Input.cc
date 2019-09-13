#include "Input.h"

using namespace std;

void readEnemysFile(istream &inFile, Keys &validKeys, vector<Enemy> &enemyList)
{
  string line;
  while (getline(inFile, line))
  {
    Enemy newEnemy;
    skipBlankLines(inFile, line);
    enemyList.push_back(readEnemy(inFile, line, validKeys));
  }
}

void readKey(string &line, string &key)
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
    throw Error("The key is not alphabetic", key);
  }
}

Keys readKeyFile(ifstream &inFile)
{
  Keys k;
  string key;
  string line;
  while (getline(inFile, line))
  {
    skipBlankLines(inFile, line);
    //Remove or check for blanks before key?
    readKey(line, key);
    k.add(key);
  }
  return k;
}

Enemy readEnemy(istream &inFile, string &line, Keys& validKeys)
{
  string key;
  string value;
  Enemy newEnemy;

  readKey(line, key);
  if(!validKeys.contains(key))
    throw Error("This key is not valid, not in provided key file", key);

  value = trim(line);

  if (!getline(inFile, line))
  {
    newEnemy.add(key, value);
  }
  
    do
  {
    if (!isspace(line[0]))
    {
      if (key.empty())
      {
        throw Error("The key is missing for this value", value);
      }
      if (value.empty())
      {
        throw Error("The value is missing for this key", key);
      }


      newEnemy.add(key, value);

      readKey(line,key);
      if(!validKeys.contains(key))
        throw Error("This key is not valid, not in provided key file", key);

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
    throw Error("The value is missing for this key", key);
  }
  newEnemy.add(key, value);

  return newEnemy;
}