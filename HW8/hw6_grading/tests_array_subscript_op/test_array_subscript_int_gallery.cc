#include "Gallery.h"
#include <cassert>
#include <string>

int main() {

    Gallery g("keys", "in2");
    
    size_t i = 0;
    std::string n1 = g[i++].field("Name");
    std::string n2 = g[i++].field("Name");

    assert((n1=="Nagini" && n2=="Salazar Slytherin's Locket")
           || (n1=="Salazar Slytherin's Locket" && n2=="Nagini"));
}
