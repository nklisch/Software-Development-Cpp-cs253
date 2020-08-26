#include "Gallery.h"
#include <cassert>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main() {
    try {
	Gallery g("e1", "keys12345", "e2", "e3", "e4", "e5");

	for (int iterations=0; iterations<1000; iterations++) {
	    // Initial sanity test
	    assert(g.size() == 5);
	    for (const auto &e : g)
		assert(e.size() == 1000);

	    // Copy & assign the Gallery.
	    Gallery gcopy(g);
	    assert(g == gcopy);
	    gcopy = g;
	    assert(g == gcopy);
	    
	    // Which slot contains the Enemy e1?
	    size_t slot = 666;
	    for (size_t i=0; i<g.size(); ++i)
		if (g[i]["Name"] == "e1") slot = i;
	    assert(slot != 666);
	    Enemy &e1 = g[slot];

	    // Copy & assign the Enemy.
	    Enemy e1copy(e1);
	    assert(e1copy.field("Name") == "e1");
	    assert(e1copy == e1);
	    e1copy = e1;
	    assert(e1copy == e1);

	    // How many chars in the strings in e1?
	    constexpr size_t desired_total = 18943;
	    size_t total = 0;
	    for (const auto &p : e1)
		total += p.first.size() + p.second.size();
	    assert(total == desired_total);

	    total = 0;
	    for (size_t i=0; i<e1.size(); ++i)
		total += e1[i].first.size() + e1[i].second.size();
	    assert(total == desired_total);
		
	    Enemy::iterator it = e1.end();
	    total = 0;
	    for (size_t i = 0; i<e1.size(); ++i) {
		--it;
		total += (*it).first.size() + (*it).second.size();
	    }
	    assert(total == desired_total);

	    // Call .field() for every key
	    for (const auto &p : e1)
		assert(e1.field(p.first) == p.second);
	}
    }
    catch (const exception &e) {
	cerr << "Unexpected exception: " << e.what() << '\n';
	return 1;
    }
    catch (...) {
	cerr << "Caught something, but it’s not a std::exception‽\n";
	return 2;
    }

    cout << "*** Done! ***\n";

    return 0;
}
