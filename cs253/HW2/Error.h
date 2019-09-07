#include <string>

using namespace std;

class Error
{
public:
  static string program_name;
  static void outputError(const string &, const string &);
};
