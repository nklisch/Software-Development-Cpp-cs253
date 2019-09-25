#include "Enemy.h"

using namespace std;
// Use a map, and a key list in the enemy, to print out the values correctly and check for valid keys// Make the keys a static value?

void Enemy::printEnemy()
{
  //for (size_t i = 0; i < this->myKeys.size(); i++)
  //{
  // cout << setw(maxCharLength + 1) << left;
  //  cout << myKeys[i] << values[i] << "\n";
  //}
}

void Enemy::add(const string &key, const string &value)
{
  if (key == "Name")
  {
    addName(key);
  }
  else if (key.find_first_of)
}

void Enemy::addName(const string &n)
{
  name.key = "Name";
  name.value = n;
}

void Enemy::addLink(const string &l, const string &v)
{
  links.push_back(EnemyProperty(l, v));
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
  for (auto &p : properties)
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