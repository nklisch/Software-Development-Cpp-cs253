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
  std::pair<string,string> toPair() const {std::pair<string,string> p; p.first = k; p.second = v; return p;};
  bool empty() const { return k.empty(); };
  void clear()
  {
    k.clear();
    v.clear();
  }
  bool operator==(const EnemyProperty& ep) const {return (k == ep.k) && (v == ep.v);};
  bool operator!=( const EnemyProperty& ep) const {return !(*this == ep);};
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
  string operator[](const string& k) const {return field(k);}
  operator bool() const {return !empty();}
  std::pair<string,string> operator[](size_t i) const {return getProperty(i).toPair();}
  bool operator==(const Enemy& e) const;
  bool operator!=(const Enemy& e) const {return !(e == *this);};
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
  const EnemyProperty& getProperty(size_t i) const;

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
