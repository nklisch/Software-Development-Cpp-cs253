#include "Error.h"

using namespace std;
string Error::program_name = "";
string Error::currentFile = "";

Error::Error()
{
  this->reason = "Default Error";
  this->data = "";
}

Error::Error(const string &r,const string& d)
{
  this->reason = r;
  this->data = d;
}

void Error::set(const string &r,const string &d){
  this->reason = r;
  this->data = d;
}

void Error::print()
{
  cerr << program_name << ": ";
  if(currentFile != "")
  {
  cerr << "File: " << currentFile << " | " << this->reason << "| Offending Data: " << this->data << endl;
  }
  else {
    cerr << ": " << this->data << endl;
  }
}