#include "Keys.h"

size_t Keys::size(){
  return keys.size();
}

string& Keys::operator[](size_t i)
{
  return keys[i];
}

void Keys::add(const string &key)
{
   if (!isAlphabetic(key))
  {
    throw Error("The key is not alphabetic", key);
  }
  if (contains(key))
  {
    throw Error("Key already exists", key);
  }
  if (key.length() > maxCharLength)
    maxCharLength = key.length();

  keys.push_back(key);
}

bool Keys::empty()
{
  return empty();
}

bool Keys::contains(const string &key)
{
  for (const string k : keys)
  {
    if (k == key)
      return true;
  }
  return false;
}

int Keys::getMaxCharLength()
{
  return maxCharLength;
}


