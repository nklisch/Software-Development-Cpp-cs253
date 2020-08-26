#include "Gallery.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


// Return index of desired Enemy or -1 if not found.
int find_by_name(const Gallery &g, const string &who) {
for (size_t i=0; i<g.size(); i++)
    if (g[i].field("Name") == who)
    return i;
return -1;          // error
}

int main() {
    try {
        Gallery villains("lorKeys", "lorVillains","/dev/null");
        assert(villains);
        assert(villains.size()== 2);
        for (const auto &e : villains){
          assert(e.size() != 6);
        }

        Gallery roles("lorRoles", "lorKeys");
        int frodo_index = find_by_name(roles, "Frodo Baggins");        
        villains.add(roles[frodo_index]);
        assert(villains.size()==3);

        Gallery::iterator it = roles.begin();
        ++it;it++;
        int galadriel_index = find_by_name(roles, "Galadriel"); 
        // where    mallorn trees of Lothlorien, the Golden Forest
        assert(roles[galadriel_index]["where"] == "mallorn trees of Lothlorien, the Golden Forest");
    }
    catch (const exception &e) {
        cerr << "Test 16: Unexpected exception: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        cerr << "Test 16: Caught something, but it’s not a std::exception‽\n";
        return 2;
    }

    cout << "*** Test 16: Done! ***\n";

    return 0;
}
