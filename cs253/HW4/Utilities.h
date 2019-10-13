#ifndef Utilities_h
#define Utilities_h
#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <algorithm>

//Finds index of first not blank char, or -1 if not found
size_t findNotBlankChar(const std::string &);
//Finds index of first not blank char from the end of string, or -1 if not found
size_t findNotBlankCharReverse(const std::string &);
//Finds index of first blank char from start of string of -1 if not found
size_t findFirstBlankChar(const std::string &);
bool isBlankLine(const std::string &);
bool isAlphaNum(const std::string &);
std::string trim(const std::string &);
#endif
