#include "Error.h"

using namespace std;
string Error::program_name = "";
string Error::currentFile = "";

void Error::set(const string &r, const string &d)
{
  reason = r;
  data = d;
}

void Error::print()
{
  cerr << "Program: \"" << program_name << "\": ";
  if (currentFile != "")
  {
    cerr << " | Input - File: \"" << currentFile << "\" | " << this->reason << "| Offending Data: " << this->data << endl;
  }
  else
  {
    cerr <<" | Input:\"cin\" | " << this->reason << "| Offending Data: " << this->data<< endl;
  }
}