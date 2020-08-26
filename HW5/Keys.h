#ifndef Keys_h
#define Keys_h

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "Utilities.h"

class Keys
{
typedef std::string string;
public:
    Keys() = default;
    Keys(string k) {keys.push_back(k);};
    void add(const string &);
    bool contains(const string &) const;
    bool empty() const {return keys.empty();};
    void clear() { keys.clear(); };
    size_t size() const  {return keys.size();};
    string &operator[](const size_t i){return keys[i];};

private:
    std::vector<string> keys;
};

#endif