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
  bool empty() { return key.empty(); }
};

class Enemy
{
public:
  Enemy() = default;
  void printEnemy(ostream &out, bool printName = true, bool printOthers = true, bool printLinks = true);
  bool hasName() const;
  //Valid alphabetic key and properly formatted value
  //Only checks for uniqueness
  void add(const string &key, const string &value);
  bool empty() const;
  string toString() const;
  static Keys validKeys;

private:
  mutable EnemyProperty name;
  vector<EnemyProperty> others;
  vector<EnemyProperty> links;
  size_t maxLinksLength = 0;
  size_t maxOthersLength = 0;
  int size = 0;
  void printName(ostream &out) const;
  void printLinks(ostream &out) const;
  void printOthers(ostream &out) const;
  bool isKeyUnique(const EnemyProperty &prop) const;
  EnemyProperty find(const string &key) const;
  size_t findMaxKeyLength(const vector<EnemyProperty> &v);
};

#endif
