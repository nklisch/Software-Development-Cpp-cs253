
#include "Utilities.h"

using namespace std;

bool isAlphabetic(const string &key)
{
  for (const auto c : key)
  {
    if (!isalpha(c))
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
  if (line.empty())
    return string::npos;

  for (auto i = line.length() - 1; i > 0; i--)
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
    if (isblank(line[i]))
      return i;
  }
  return string::npos;
}

bool isBlankLine(const string &line)
{
  if (line.empty())
    return true;
  if (findNotBlankChar(line) != string::npos)
    return false;

  return true;
}

string trim(const string &line)
{
   
  auto index = 'v';
  index = findNotBlankChar(line);

  if (index == string::npos)
    return "";

  size_t length = findNotBlankCharReverse(line) - index +1;
  return line.substr(index, length);
}
