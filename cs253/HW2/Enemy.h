#include <string>
#include <vector>
using namespace std;

class Enemy
{

private:
  bool isKeyunique(const string &);
  int maxCharLength;
  vector<string> keys;
  vector<string> values;

public:
  Enemy();
  void printEnemy();
  //Valid alphabetic key and properly formatted value
  //Only checks for uniqueness
  bool add(const string &key, const string &value);
  bool empty();
};
