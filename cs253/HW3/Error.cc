#include "Error.h"

using namespace std;
string Error::program_name = "";
string Error::currentInput = "N/A";
void Error::set(const string &r, const string &d)
{
  reason = r;
  data = d;
}

ostream &
operator<<(ostream &os, const Error &e)
{
  return os << "Program: \"" << Error::program_name << "\": "
            << " | Input: \"" << Error::currentInput << "\" | " << e.getReason()
            << "| Offending Data: " << e.getData() << endl;
}