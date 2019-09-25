#ifndef Error_h
#define Error_h
#include <iostream>
#include <string>

using namespace std;

class Error
{
public:
  Error() = default;
  Error(const string &r, const string &d) : reason(r), data(d){};
  void set(const string &r, const string &d);
  void print();
  static string program_name;
  static string currentInput;

private:
  string reason = "Default Error";
  string data = "";
};
#endif