#include "Error.h"
#include <iostream>
#include <string>

using namespace std;
string Error::program_name = "";

void Error::outputError(const string &data, const string &reason)
{
  cerr << Error::program_name << "- Error! Reason: " << reason << "Offending Data: " << data
       << "\n";
}
