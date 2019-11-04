#include "Gallery.h"
#include "Utilities.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;


Gallery::Gallery(const string& f1, const string& f2)
{
    files.push_back(f1);
    files.push_back(f2);
    create();
}
Gallery::Gallery(const string& f1, const string& f2, const string& f3)
{
    files.push_back(f1);
    files.push_back(f2);
    files.push_back(f3);
    create();
}
Gallery::Gallery(const string& f1, const string& f2, const string& f3, const string& f4)
{
files.push_back(f1);
    files.push_back(f2);
    files.push_back(f3);
    files.push_back(f4);
    create();
}
Gallery::Gallery(const string& f1, const string& f2, const string& f3, const string& f4, const string& f5){
    files.push_back(f1);
    files.push_back(f2);
    files.push_back(f3);
    files.push_back(f4);
    files.push_back(f5);
    create();
}
Gallery::Gallery(const string& f1, const string& f2, const string& f3, const string& f4, const string& f5, const string& f6)
{
    files.push_back(f1);
    files.push_back(f2);
    files.push_back(f3);
    files.push_back(f4);
    files.push_back(f5);
    files.push_back(f6);
    create();
}

void Gallery::read(const string &filename, const string &keyfile)
{
Enemy e(keyfile, this);
ifstream inFile(filename);
while(e.read(inFile)){
    add(e);
}
}

size_t Gallery::findKeyfile() const
{
    size_t key = string::npos;
    for(size_t i = 0; i < files.size(); i++)
    {
        if(isKeyfile(files[i]))
        {
            if(key != string::npos)
                throw runtime_error("Too many keyfiles! Keyfile: " + files[i]);
            key = i;
        }
    }
    if(key == string::npos)
        throw runtime_error("No keyfile provided!");
    return key;
}

void Gallery::create(){
    string keyfile;
    size_t index;
    index = findKeyfile();
    keyfile = files[index];
    files.erase(files.begin() + index);
    for(const auto &f : files){
        read(f, keyfile);
    }
}

bool Gallery::isKeyfile(const string& filename) const
{
ifstream infile(filename);
if(!infile)
    throw runtime_error("File " + filename +" provided did not open");
string line;
bool flag = false;
while(getline(infile, line))
    {
    if(line.empty())
        return false;
    if(hasBlanks(line))
        return false;
    if(!isAlphaNum(line))
        return false;
    flag = true;
    }

return flag;
}

ostream& operator<<(ostream& os, const Gallery & g)
{
    for(size_t i = 0; i < g.collection.size(); i++){
        os << g.collection[i];
        if(i < g.collection.size() - 1)
            os << '\n';
    }
    return os;
}