#ifndef Enemy_h
#define Enemy_h

#include "Error.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "Utilities.h"
#include "Keys.h"

using namespace std;

class Enemy
{

private:
  bool isKeyunique(const string &);
  int maxCharLength = 0;
  Keys myKeys;
  vector<string> values;

public:
  Enemy() = default;
  void printEnemy();
  //Valid alphabetic key and properly formatted value
  //Only checks for uniqueness
  void add(const string &key, const string &value);
  bool empty();
};

#endif
