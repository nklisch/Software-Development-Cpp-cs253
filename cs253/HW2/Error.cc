#include "Error.h"
#include <iostream>
#include <string>

using namespace std;
string Error::program_name = "";

void Error::outputError(const string &reason, const string &data)
{
  cerr << Error::program_name << "- Error! Reason: " << reason << "  Offending Data: " << data
       << "\n";
}
