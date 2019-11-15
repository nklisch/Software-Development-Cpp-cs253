#include "Keys.h"
#include <stdexcept>
#include <unordered_map>
using namespace std;

void Keys::add(const string &key)
{
  if (contains(key))
  {
    throw runtime_error("This key: " + key + ",already exists");
  }
  keys[key] = string::npos;
}

size_t Keys::getIndex(const string &s) const
{
  auto found = keys.find(s);
  if (found == keys.end())
    return string::npos;
  return found->second;
}