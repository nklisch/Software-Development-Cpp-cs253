#include "Enemy.h"


using namespace std;
// Use a map, and a key list in the enemy, to print out the values correctly and check for valid keys// Make the keys a static value?

void Enemy::printEnemy()
{
  for (size_t i = 0; i < this->myKeys.size(); i++)
  {
    cout << setw(myKeys.getMaxCharLength() + 1) << left;
    cout << myKeys[i] << values[i] << "\n";
  }
}

void Enemy::add(const string &key, const string &value)
{
  myKeys.add(key);
  values.push_back(value);
}

bool Enemy::empty()
{
  return myKeys.empty();
}


