#include <string>

using namespace std;

//Finds index of first not blank char, or -1 if not found
int findNotBlankChar(const string &);
//Finds index of first not blank char from the end of string, or -1 if not found
int findNotBlankCharReverse(const string &);
//Finds index of first blank char from start of string of -1 if not found
int findFirstBlankChar(const string &);
bool isBlankLine(const string &);
bool isAlphabetic(const string &);
string trim(const string &);
