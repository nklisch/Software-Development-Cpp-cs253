#ifndef Enemy_h
#define Enemy_h
#include "Utilities.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
class Gallery;

class Enemy
{
  typedef std::string string;
  typedef std::ostream ostream;
  typedef std::istream istream;

public:
  Enemy() = delete;
  Enemy(const string &keyfile, Gallery *g = nullptr);
  Enemy(istream &input, Gallery *g = nullptr);
  typedef std::map<string, string>::const_iterator iterator;
  Enemy::iterator begin() const {return keyValues.begin();};
  Enemy::iterator end() const {return keyValues.end();}
  bool read(istream &input);
  void write(ostream &out) const;
  void write(const string &filename) const;
  string field(const string &key) const;
  Enemy *link(const string &) const;
  void show_name(bool flag = true) { showName = flag; };
  void show_other(bool flag = true) { showOther = flag; };
  void show_link(bool flag = true) { showLink = flag; };
  const string& getName() const { return name; };
  void clear();
  size_t size() const { return mySize; };
  bool empty() const { return !mySize; };
  string operator[](const string &k) const { return field(k); }
  operator bool() const { return !empty(); }
  std::pair<string, string> operator[](size_t i) const;
  bool operator==(const Enemy &e) const;
  bool operator!=(const Enemy &e) const { return !(e == *this); };
  friend ostream &operator<<(ostream &out, const Enemy &e);

private:
  Gallery *myGallery;
  std::set<string> validKeys;
  std::map<string,string> keyValues;
  bool showName = false;
  bool showOther = false;
  bool showLink = false;
  const size_t nameSize = 4;
  string name;
  std::vector<string> otherKeys;
  std::vector<string> linkKeys;
  size_t maxLinksLength = 0;
  size_t maxOthersLength = 0;
  size_t mySize = 0;
  void readKey(string &line, string &key);
  void readKeyFile(istream &input);
  void readEnemy(istream &input, string &line);
  void readValue(istream &input, string &line, string &value);
  bool hasName() const { return !name.empty(); };
  void add(const string &key, const string &value);
  void writeName(ostream &out, int maxLength) const;
  void writeLinks(ostream &out, int maxLength) const;
  void writeOthers(ostream &out, int maxLength) const;
  bool isKeyUnique(const string &key) const;
  string toString() const;
};

#endif
