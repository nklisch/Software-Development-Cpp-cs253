#include <iostream>
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
    newEnemy.add(key, value);
    getline(cin, line);
  } while (!isBlankLine(line));
  return true;
}

bool readStdValue(string &line, string &value)
{
  int index = findNotBlankChar(line);

  if (index < 0)
    return false;

  int length = findNotBlankCharReverse(line) - index + 1;
  value = line.substr(index, length);
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

//bool readFileInput(string &keys, vector<string> inFiles, vector<Enemy> &enemyList) {}
