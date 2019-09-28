#include "Enemy.h"

using namespace std;

Keys Enemy::validKeys;

void Enemy::printEnemy(ostream &out, bool printN, bool printO, bool printL)
{
  size_t maxLength = 0;
  if (printN && name.key.length() > maxLength)
    maxLength = name.key.length();
  if (printO && maxOthersLength > maxLength)
    maxLength = maxOthersLength;
  if (printL && maxLinksLength > maxLength)
    maxLength = maxLinksLength;
  out << left;
  if (printN)
    printName(out, maxLength);
  if (printO)
    printOthers(out, maxLength);
  if (printL)
    printLinks(out, maxLength);
}

void Enemy::printName(ostream &out, int maxLength) const
{
  out << setw(maxLength + 1);
  out << name.key << name.value << "\n";
}

void Enemy::printLinks(ostream &out, int maxLength) const
{
  for (auto &l : links)
  {
    out << setw(maxLength + 1);
    out << l.key << l.value << "\n";
  }
}

void Enemy::printOthers(ostream &out, int maxLength) const
{
  for (auto &o : others)
  {
    out << setw(maxLength + 1);
    out << o.key << o.value << "\n";
  }
}

void Enemy::add(const string &key, const string &value)
{
  EnemyProperty p(key, value);
  if (!validKeys.contains(p.key))
    throw Error("This key is not valid, not in provided key file", key);
  if (!isKeyUnique(p))
    throw Error("Key not unique", key);
  if (p.value.empty())
    throw Error("The value is missing for this key", p.key);

  if (p.key == "Name")
  {
    name = p;
  }
  else if (key.find("Link") != string::npos)
  {
    links.push_back(p);
    if (p.key.length() > maxLinksLength)
      maxLinksLength = p.key.length();
  }
  else
  {
    others.push_back(p);
    if (p.key.length() > maxOthersLength)
      maxOthersLength = p.key.length();
  }
}

string Enemy::toString() const
{
  string s(name.key + " " + name.value);
  for (auto &l : links)
    s += "\n" + l.key + " " + l.value;
  for (auto &o : others)
    s += "\n" + o.key + " " + o.value;
  return s;
}

bool Enemy::hasName() const
{
  return !name.empty();
}

bool Enemy::empty() const
{
  return size == 0;
}

bool Enemy::isKeyUnique(const EnemyProperty &prop) const
{
  return find(prop.key).empty();
}

EnemyProperty Enemy::find(const string &key) const
{
  if (key == name.key)
    return name;
  for (auto &p : others)
  {
    if (key == p.key)
      return p;
  }
  for (auto &l : links)
  {
    if (key == l.key)
      return l;
  }
  return EnemyProperty();
}