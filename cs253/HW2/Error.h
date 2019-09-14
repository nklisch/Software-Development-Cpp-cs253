#ifndef Error_h
#define Error_h
#include <iostream>
#include <string>

using namespace std;

class Error
{
  private:
  string reason;
  string data;
  public:
  Error();
  Error(const string&, const string&);
  void set(const string&,const string&);
  void print();
  static string program_name;
  static string currentFile;
};
#endif 