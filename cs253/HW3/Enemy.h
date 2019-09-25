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

struct EnemyProperty
{
  string key;
  string value;
  EnemyProperty() = default;
  EnemyProperty(const string &k, const string &v) : key(k), value(v){};
  bool empty()
  {
    return key.empty();
  }
};

class Enemy
{

private:
  bool isKeyUnique(const EnemyProperty &prop) const;
  EnemyProperty find(const string &key) const;
  void formatOutput(ostream &out, size_t width);
  size_t findMaxKeyLength(const vector<EnemyProperty> &v);
  EnemyProperty name;
  vector<EnemyProperty> others;
  vector<EnemyProperty> links;
  size_t maxKeyLength = 0;
  int size = 0;

public:
  Enemy() = default;
  void printEnemy(ostream &out);
  void printName(ostream &out, bool format = true);
  void printLinks(ostream &out, bool format = true);
  void printOthers(ostream &out, bool format = true);
  bool hasName();
  //Valid alphabetic key and properly formatted value
  //Only checks for uniqueness
  void add(const string &key, const string &value);
  bool empty();
};

#endif
