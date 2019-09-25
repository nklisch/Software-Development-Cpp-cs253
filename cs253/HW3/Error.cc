#include "Error.h"

using namespace std;
string Error::program_name = "";
string Error::currentInput = "N/A";
void Error::set(const string &r, const string &d)
{
  reason = r;
  data = d;
}

void Error::print()
{
  cerr << "Program: \"" << program_name << "\": "
       << " | Input: \"" << currentInput << "\" | " << reason
       << "| Offending Data: " << data << endl;
}