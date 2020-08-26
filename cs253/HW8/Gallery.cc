#include "Gallery.h"
#include "Utilities.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>

using namespace std;

Gallery::Gallery(const string &f1, const string &f2)
{
    fill(f1);
    fill(f2);
    create();
}
Gallery::Gallery(const string &f1, const string &f2, const string &f3)
{
    files.reserve(3);
    fill(f1);
    fill(f2);
    fill(f3);
    create();
}
Gallery::Gallery(const string &f1, const string &f2, const string &f3, const string &f4)
{
    files.reserve(4);
    fill(f1);
    fill(f2);
    fill(f3);
    fill(f4);
    create();
}
Gallery::Gallery(const string &f1, const string &f2, const string &f3, const string &f4, const string &f5)
{
    files.reserve(5);
    fill(f1);
    fill(f2);
    fill(f3);
    fill(f4);
    fill(f5);
    create();
}
Gallery::Gallery(const string &f1, const string &f2, const string &f3, const string &f4, const string &f5, const string &f6)
{
    files.reserve(6);
    fill(f1);
    fill(f2);
    fill(f3);
    fill(f4);
    fill(f5);
    fill(f6);
    create();
}

void Gallery::fill(const string &file)
{
std::pair<string, int> p;
p.second = 1;
p.first = file;
bool flag = true;
for( auto &f : files)
{
if(f.first == file){
	f.second++;
	flag = false;
}
} 
if(flag)
	files.push_back(p);
}

void Gallery::read(const string &file, const string &keyfile)
{
    ifstream inFile(file);
    ifstream keys(keyfile);
    if(!keys)
        throw runtime_error("Key file " + keyfile + " failed to open.");
    if(!inFile)
        throw runtime_error("File " + file + " failed to open.");
    readFromStream(inFile,keys,1);
}

void Gallery::readFromStream(istream &inFile, istream &keyfile, int number)
{
    Enemy e(keyfile, this);
    while (e.read(inFile))
    {
	for(int i = 0; i < number;i++)
        {add(e);}
    }
}

void Gallery::create()
{
    ifstream openFiles[6];
    size_t keyfileIndex = string::npos;
    for (size_t i = 0; i < files.size(); i++)
    {
        openFiles[i].open(files[i].first);
        if (!openFiles[i])
            throw runtime_error("File " + files[i].first + " provided did not open");
        if (isKeyfile(openFiles[i]))
        {
            if (keyfileIndex != string::npos)
                throw runtime_error("Too many keyfiles! Keyfile: " + files[i].first);
            keyfileIndex = i;
        }
    }

    if (keyfileIndex == string::npos)
        throw runtime_error("No keyfile provided!");
    
    for (size_t i = 0; i < files.size(); i++)
    {
        if (i != keyfileIndex)
        {
            openFiles[keyfileIndex].clear();
            openFiles[keyfileIndex].seekg(ios_base::beg);
            openFiles[i].clear();
            openFiles[i].seekg(ios_base::beg);
            readFromStream(openFiles[i], openFiles[keyfileIndex],files[i].second);
        }
    }
}

bool Gallery::isKeyfile(istream &infile) const
{
    string line;
    bool flag = false;
    while (getline(infile, line))
    {
        if (line.empty())
            return false;
        if (hasBlanks(line))
            return false;
        if (!isAlphaNum(line))
            return false;
        flag = true;
    }
    return flag;
}
Enemy *Gallery::get(size_t n)
{
    if (n >= size())
        throw range_error("Index out of bounds: " + to_string(n) + " max is " + to_string(size()));

    return &collection[n];
}

const Enemy *Gallery::get(size_t n) const
{
    if (n >= size())
        throw range_error("Index out of bounds: " + to_string(n) + " max is " + to_string(size()));
    return &collection[n];
}

ostream &operator<<(ostream &os, const Gallery &g)
{
    for (size_t i = 0; i < g.collection.size(); i++)
    {
        os << g.collection[i];
        if (i < g.collection.size() - 1)
            os << '\n';
    }
    return os;
}
