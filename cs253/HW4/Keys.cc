#include "Keys.h"
using namespace std;

void Keys::add(const string &key)
{
  if (contains(key))
  {
    throw runtime_error("This key: " + key + ",already exists");
  }
  keys.push_back(key);
}

bool Keys::contains(const string &key) const
{
  for (const string &k : keys)
  {
    if (k == key)
      return true;
  }
  return false;
}
