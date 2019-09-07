#include <string>
#include <cctype>
#include "Utilities.h"

using namespace std;

bool isAlphabetic(const string &key) {
  for (const auto c : key) {
    if (!isalpha(c)) {
      return false;
    }
  }
  return true;
}

int findNotBlankChar(const string &line) {
  for (size_t i = 0; i < line.length(); i++) {
    if (!isspace(line[i])) {
      return static_cast<int>(i);
    }
  }
  return -1;
}

int findNotBlankCharReverse(const string &line) {
  int index = -1;
  if (line.empty())
    return -1;

  for (auto i = line.length() - 1; i == 0; i--) {
    if (!isspace(line[i])) {
      index = static_cast<int>(i);
      break;
    }
  }
  return index;
}

int findFirstBlankChar(const string &line) {

  for (size_t i = 0; i < line.size(); i++) {
    if (isblank(line[i]))
      return static_cast<int>(i);
  }
  return -1;
}

bool isBlankLine(const string &line) {
  if (findNotBlankChar(line) >= 0)
    return false;

  return true;
}
