#ifndef Utilities_h
#define Utilities_h
#include <string>
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

//Finds index of first not blank char, or -1 if not found
size_t findNotBlankChar(const string &);
//Finds index of first not blank char from the end of string, or -1 if not found
size_t findNotBlankCharReverse(const string &);
//Finds index of first blank char from start of string of -1 if not found
size_t findFirstBlankChar(const string &);
bool isBlankLine(const string &);
bool isAlphabetic(const string &);
string trim(const string &);

#endif
