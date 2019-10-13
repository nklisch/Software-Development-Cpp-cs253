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
public:
    Keys() = default;
    void add(const string &);
    bool contains(const string &) const;
    bool empty() const;
    void clear() { keys.clear(); };
    size_t size() const;
    string &operator[](const size_t);

private:
    vector<string> keys;
};

#endif