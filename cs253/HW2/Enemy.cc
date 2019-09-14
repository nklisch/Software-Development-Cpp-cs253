#include "Enemy.h"


using namespace std;
// Use a map, and a key list in the enemy, to print out the values correctly and check for valid keys// Make the keys a static value?
Enemy::Enemy()
{
}

void Enemy::printEnemy()
{
  for (size_t i = 0; i < this->myKeys.size(); i++)
  {
    cout << setw(this->myKeys.getMaxCharLength() + 1) << left;
    cout << this->myKeys[i] << this->values[i] << "\n";
  }
}

void Enemy::add(const string &key, const string &value)
{
  this->myKeys.add(key);
  this->values.push_back(value);
}

bool Enemy::empty()
{
  return this->myKeys.empty();
}


