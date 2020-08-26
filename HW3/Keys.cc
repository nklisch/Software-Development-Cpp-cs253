#include "Keys.h"

size_t Keys::size() const
{
  return keys.size();
}

string &Keys::operator[](const size_t i)
{
  return keys[i];
}

void Keys::add(const string &key)
{
  if (contains(key))
  {
    throw Error("Key already exists", key);
  }
  keys.push_back(key);
}

bool Keys::empty() const
{
  return keys.empty();
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
