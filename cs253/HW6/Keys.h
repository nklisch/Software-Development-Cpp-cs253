#ifndef Keys_h
#define Keys_h
#include "Utilities.h"
#include <string>
#include <unordered_map>

class Keys
{
    typedef std::string string;

public:
    Keys() = default;
    Keys(const string &k) { keys[k] = string::npos; };
    void add(const string &);
    void setIndex(const string &s, size_t i) { keys[s] = i; };
    size_t getIndex(const string &s) const;
    bool contains(const string &key) const { return keys.end() != keys.find(key); };
    bool empty() const { return keys.empty(); };
    void clear() { keys.clear(); };
    size_t size() const { return keys.size(); };

private:
    std::unordered_map<string, size_t> keys;
};

#endif