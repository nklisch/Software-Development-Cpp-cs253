#include "Keys.h"

Keys::Keys()
{
  this->maxCharLength = 0;
}

size_t Keys::size(){
  return this->keys.size();
}

string& Keys::operator[](size_t i)
{
  return keys[i];
}

void Keys::add(const string &key)
{
  if (this->contains(key))
  {
    throw Error("Key already exists", key);
  }
  if (key.length() > this->maxCharLength)
    this->maxCharLength = key.length();

  keys.push_back(key);
}

bool Keys::empty()
{
  return this->empty();
}

bool Keys::contains(const string &key)
{
  for (const string k : this->keys)
  {
    if (k == key)
      return true;
  }
  return false;
}

int Keys::getMaxCharLength()
{
  return this->maxCharLength;
}


