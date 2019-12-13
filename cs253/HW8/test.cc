#include "Gallery.h"
#include <iostream>
#include <cassert>
using namespace std;
int main() {
	for(auto i = 0; i < 500; i++) {
		Gallery gallery("enemiesFile", "enemiesFile", "enemiesFile", "enemiesFile", "enemiesFile", "keyFile");
		Gallery copy(gallery);
//        cout << gallery;
		copy.read("enemiesFile", "keyFile");
		assert(gallery[0] == gallery[0]);
		assert(gallery[0] != gallery[5]);
  //      cout << copy;
		gallery = copy;
	}
	return 0;
}
