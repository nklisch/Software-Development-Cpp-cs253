#ifndef Enemy_h
#define Enemy_h
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Utilities.h"
#include "Keys.h"

class EnemyProperty
{
  public:
  typedef std::string string;
  
  EnemyProperty() = default;
  EnemyProperty(const std::string &_k, const string &_v) : k(_k), v(_v){};
  const string& key()const {return k;};
  const string& value()const {return v;};
  bool empty() const { return k.empty(); }
  void clear()
  {
    k.clear();
    v.clear();
  }
  private:
  string k;
  string v;
};
class Gallery;

class Enemy
{
  typedef std::string string;
  typedef std::ostream ostream;
  typedef std::istream istream;

public:
  Enemy() = delete;
  Enemy(const string& keyfile);
  Enemy(const string& keyfile, Gallery * g);
  bool read(istream &input);
  void write(ostream &out) const;
  void write(const string &filename) const;
  string field(const string &key) const;
  Enemy * link(const string&) const;
  void show_name(bool flag = true) { showName = flag; };
  void show_other(bool flag = true) { showOther = flag; };
  void show_link(bool flag = true) { showLink = flag; };
  string getName() const {return name.value();};
  void clear();
  size_t size() const { return mySize; };
  bool empty() const { return mySize == 0; };
  friend ostream &operator<<(ostream &out, const Enemy &e);

private:
  Gallery * myGallery;
  Keys validKeys;
  bool showName = false;
  bool showOther = false;
  bool showLink = false;
  EnemyProperty name;
  std::vector<EnemyProperty> others;
  std::vector<EnemyProperty> links;
  size_t maxLinksLength = 0;
  size_t maxOthersLength = 0;
  size_t mySize = 0;
  //Functions to read information in
  void readKey(string &line, string &key);
  void readKeyFile(istream &input, Keys &k);
  void readEnemy(istream &input, string &line);
  void readValue(istream &input, string &line, string &value);

  bool hasName() const { return !name.empty(); };
  void add(const string &key, const string &value);
  void writeName(ostream &out, int maxLength) const;
  void writeLinks(ostream &out, int maxLength) const;
  void writeOthers(ostream &out, int maxLength) const;
  bool isKeyUnique(const EnemyProperty &prop) const { return find(prop.key()).empty(); };
  EnemyProperty find(const string &key) const;
  string toString() const;
};

#endif
