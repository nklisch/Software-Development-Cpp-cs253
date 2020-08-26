// Nathan Klisch
// cs253, Fall2019
// HW2
#include <cctype>
#include <iomanip>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <sstream>
#include "Enemy.h"

using namespace std;

int main()
{
	const Enemy a;
	assert(a.empty());
	assert(a.size() == 0);

	ifstream lair("pony-villains");
	assert(lair);
	Enemy b("keys"), c, d;
	bool got_b = b.read(lair);
	bool got_c = c.read(lair);
	bool got_d = d.read(lair);

	assert(got_b);
	assert(b.size() == 5);
	assert(!b.empty());

	assert(got_c);
	assert(c.size() == 4);
	assert(!c.empty());

	assert(!got_d);

	cout << b << "————–————––————–\n"
		 << c;

	b = c;
	assert(b.size() == 4);

	assert(b.field("BodyType"s) == "Chimera");

	c.show_other(false);
	cout << "::::::::\n"
		 << c;
	c.show_other();
	c.show_link(false);
	cout << "********\n"
		 << c;

	stringstream iss("\n\n\nName \t\v\f xyz  \n\n\n");
	assert(c.read(iss));
	assert(c.size() == 1);
	assert(c.field("Name") == "xyz");
	ostringstream oss;
	assert(oss << c);
	cout << oss.str();
	assert(oss.str() == "Name xyz\n");

	// Try a field that’s not there:
	try
	{
		string s = b.field("foobar");
		cerr << "ERROR: .field() worked?\n";
	}
	catch (const range_error &err)
	{
		cout << "Good, range_error = " << err.what() << '\n';
	}
	catch (const exception &err)
	{
		cerr << "ERROR: exception = " << err.what() << '\n';
	}
	catch (...)
	{
		cerr << "ERROR: What the ☆⚡🔪☠§❢💣 did you throw?\n";
	}

	return 0;
}