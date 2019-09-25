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
  void addName(const string &n);
  void addLink(const string &l, const string &v);
  int maxCharLength = 0;
  EnemyProperty name;
  vector<EnemyProperty> properties;
  vector<EnemyProperty> links;
  int size = 0;

public:
  Enemy() = default;
  void printEnemy();
  //Valid alphabetic key and properly formatted value
  //Only checks for uniqueness
  void add(const string &key, const string &value);
  bool empty();
};

#endif
