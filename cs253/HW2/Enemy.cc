#include "Enemy.h"
#include "Error.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Enemy::Enemy()
{
  this->maxCharLength = 0;
}

void Enemy::printEnemy()
{
  for (size_t i = 0; i < this->keys.size(); i++)
  {
    cout << setw(this->maxCharLength + 1) << left;
    cout << this->keys[i] << this->values[i] << "\n";
  }
}
bool Enemy::isKeyunique(const string &key)
{
  for (const string &k : this->keys)
  {
    if (key == k)
      return false;
  }
  return true;
}

bool Enemy::add(const string &key, const string &value)
{
  if (!isKeyunique(key))
  {
    Error::outputError("This key is already used!", key);
    return false;
  }
  if (static_cast<int>(key.length()) > this->maxCharLength)
    this->maxCharLength = static_cast<int>(key.length());

  this->keys.push_back(key);
  this->values.push_back(value);
  return true;
}

bool Enemy::empty()
{
  return this->keys.empty();
}
