#ifndef Keys_h
#define Keys_h
#include "Utilities.h"
#include <string>
#include <set>

class Keys
{
    typedef std::string string;

public:
    Keys() = default;
    void add(const string &);
    bool contains(const string &key) const { return keys.end() != keys.find(key); };
    bool empty() const { return keys.empty(); };
    void clear() { keys.clear(); };
    size_t size() const { return keys.size(); };

private:
    std::set<string> keys;
};

#endif