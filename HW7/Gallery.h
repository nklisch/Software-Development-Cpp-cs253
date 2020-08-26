
#ifndef Gallery_h
#define Gallery_h
#include <string>
#include <vector>
#include "Enemy.h"
typedef std::string string;
typedef std::istream istream;
class Gallery
{
public:
	typedef std::vector<Enemy>::const_iterator iterator;
	Gallery(const string &f1, const string &f2);
	Gallery(const string &f1, const string &f2, const string &f3);
	Gallery(const string &f1, const string &f2, const string &f3, const string &f4);
	Gallery(const string &f1, const string &f2, const string &f3, const string &f4, const string &f5);
	Gallery(const string &f1, const string &f2, const string &f3, const string &f4, const string &f5, const string &f6);

	//Gallery::iterator begin(){return collection.begin();};
	//Gallery::iterator end(){return collection.end();};
	Gallery::iterator begin() const {return collection.begin();};
	Gallery::iterator end() const {return collection.end();};
	void read(const string &file, const string &keyfile);
	void add(const Enemy &e) { collection.push_back(e); };
	void clear() { collection.clear(); };
	size_t size() const { return collection.size(); };
	bool empty() const { return collection.empty(); };
	const Enemy *get(size_t n) const;
	Enemy *get(size_t n);
	Enemy &operator[](size_t n) { return *get(n); };
	const Enemy &operator[](size_t n) const { return *get(n); };
	operator bool() const { return !empty(); }
	friend std::ostream &operator<<(std::ostream &os, const Gallery &g);

private:
	std::vector<string> files;
	void readFromStream(istream &inFile, istream &keyfile);
	void create();
	bool isKeyfile(istream &infile) const;
	std::vector<Enemy> collection;
};

#endif