
#include "Utilities.h"

using namespace std;

bool isAlphaNum(const string &key)
{
  for (const auto c : key)
  {
    if (!isalnum(c))
    {
      return false;
    }
  }
  return true;
}

size_t findNotBlankChar(const string &line)
{
  for (size_t i = 0; i < line.length(); i++)
  {
    if (!isspace(line[i]))
    {
      return i;
    }
  }
  return string::npos;
}

size_t findNotBlankCharReverse(const string &line)
{

  for (size_t i = line.length() - 1; i != string::npos; i--)
  {
    if (!isspace(line[i]))
    {
      return i;
    }
  }
  return string::npos;
}

size_t findFirstBlankChar(const string &line)
{
  for (size_t i = 0; i < line.size(); i++)
  {
    if (isspace(line[i]))
      return i;
  }
  return string::npos;
}

bool isBlankLine(const string &line)
{
  return trim(line).empty();
}

string trim(const string &line)
{
  size_t index = findNotBlankChar(line);

  if (index == string::npos)
    return "";

  size_t length = findNotBlankCharReverse(line) - index + 1;
  return line.substr(index, length);
}

void removeBlankLines(istream &in, string& line)
{
  while (getline(in, line) && isBlankLine(line));
}