
#ifndef Gallery_h
#define Gallery_h
#include <string>
#include <vector>
#include "Enemy.h"


class Gallery
{
public:
typedef std::string string;
Gallery(const string& f1, const string& f2);
Gallery(const string& f1, const string& f2, const string& f3);
Gallery(const string& f1, const string& f2, const string& f3, const string& f4);
Gallery(const string& f1, const string& f2, const string& f3, const string& f4, const string& f5);
Gallery(const string& f1, const string& f2, const string& f3, const string& f4, const string& f5, const string& f6);

void read(const string &filename, const string &keyfile);
void add(const Enemy &e){collection.push_back(e);};
void clear() {collection.clear();};
size_t size() const {return collection.size();};
bool empty() const {return collection.size() == 0;};
const Enemy* get(size_t n) const {return &collection[n];};
Enemy * get(size_t n) {return &collection[n];};
friend std::ostream& operator<<(std::ostream& os, const Gallery & g);

private:
std::vector<string> files;
void create();
size_t findKeyfile() const;
bool isKeyfile(const string& filename) const;
std::vector<Enemy> collection;
};

#endif