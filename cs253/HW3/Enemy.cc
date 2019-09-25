#include "Enemy.h"

using namespace std;

void Enemy::printEnemy(ostream &out)
{
  formatOutput(out, maxKeyLength);
  printName(out, false);
  printOthers(out, false);
  printLinks(out, false);
}

void Enemy::printName(ostream &out, bool format = true)
{
  if (format)
    formatOutput(out, name.key.length());

  out << name.key << name.value << "\n";
}

void Enemy::printLinks(ostream &out, bool format = true)
{
  if (format)
    formatOutput(out, findMaxKeyLength(links));

  for (auto &l : links)
  {
    out << l.key << l.value << "\n";
  }
}

void Enemy::printOthers(ostream &out, bool format = true)
{
  if (format)
    formatOutput(out, findMaxKeyLength(others));

  for (auto &o : others)
  {
    out << o.key << o.value << "\n";
  }
}

void Enemy::formatOutput(ostream &out, size_t width)
{
  out << setw(width) << left;
}

void Enemy::add(const string &key, const string &value)
{
  EnemyProperty p(key, value);

  if (!isKeyUnique(p))
    throw Error("Key not unique", key);
  if (p.key == "Name")
  {
    name = p;
  }
  else if (key.find("Link") != 0)
  {
    links.push_back(p);
  }
  else
  {
    others.push_back(p);
  }

  if (p.key.length() > maxKeyLength)
    maxKeyLength = p.key.length();
}

size_t Enemy::findMaxKeyLength(const vector<EnemyProperty> &v)
{
  size_t max = 0;
  for (auto &s : v)
  {
    if (s.key.length() > max)
      max = s.key.length();
  }
}

bool Enemy::hasName()
{
  return !name.empty();
}

bool Enemy::empty()
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
  EnemyProperty p;
  return p;
}