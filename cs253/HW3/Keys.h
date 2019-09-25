#ifndef Keys_h
#define Keys_h

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Error.h"
#include "Utilities.h"

class Keys
{
private:
    vector<string> keys;

public:
    Keys() = default;
    void add(const string &);
    bool contains(const string &) const;
    bool empty() const;
    size_t size() const;
    string &operator[](const size_t);
};

#endif