#include "Keys.h"
#include <stdexcept>
#include <unordered_map>
using namespace std;

void Keys::add(const string &key)
{
  auto result = keys.insert(key);
  if (!result.second)
  {
    throw runtime_error("This key: " + key + " already exists");
  }
}