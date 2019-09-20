#ifndef Keys_h
#define Keys_h

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Error.h"
#include "Utilities.h"

class Keys {
private:
    vector<string> keys;
    size_t maxCharLength = 0;
public:
    Keys() = default;
    void add(const string&);
    bool contains(const string&);
    int getMaxCharLength();
    bool empty();
    size_t size();
    string& operator[](size_t);

};

#endif