#ifndef Enemy_h
#define Enemy_h

#include "Error.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "Utilities.h"
#include "Keys.h"

struct EnemyProperty
{
  string key;
  string value;
  EnemyProperty() = default;
  EnemyProperty(const string &k, const string &v) : key(k), value(v){};
  bool empty() { return key.empty(); }
  void clear()
  {
    key.clear();
    value.clear();
  }
};

class Enemy
{
  typedef std::string string;
  typedef std::ostream ostream;
  typedef std::istream istream;

public:
  Enemy() = default;
  Enemy(string keyfile);
  void read(istream &input);
  void write(ostream &out) const;
  void write(const string &filename) const;
  string field(const string &key) const;
  void show_name(bool flag = true) { showName = flag; };
  void show_other(bool flag = true) { showOther = flag; };
  void show_link(bool flag = true) { showLink = flag; };
  void clear();
  size_t size() const { return mySize; };
  bool empty() const { return mySize == 0; };

private:
  Keys validKeys;
  bool showName = true;
  bool showOther = true;
  bool showLink = true;
  mutable EnemyProperty name;
  vector<EnemyProperty> others;
  vector<EnemyProperty> links;
  size_t maxLinksLength = 0;
  size_t maxOthersLength = 0;
  size_t mySize = 0;
  //Functions to read information in
  void readKey(string &line, string &key);
  void readKeyFile(ifstream &input, Keys &k);
  void readEnemy(istream &input, string &line);
  void readValue(istream &input, string &line, string &value);

  bool hasName() const { return !name.empty(); };
  void add(const string &key, const string &value);
  void writeName(ostream &out, int maxLength) const;
  void writeLinks(ostream &out, int maxLength) const;
  void writeOthers(ostream &out, int maxLength) const;
  bool isKeyUnique(const EnemyProperty &prop) const { return find(prop.key).empty(); };
  EnemyProperty find(const string &key) const;
  string toString() const;
};

#endif
