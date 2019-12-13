#include "Gallery.h"
#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <sstream>

// 
using namespace std;

int main() {
  Gallery g("file5","file0");
  Enemy *e = g.get(0);
  try{
    Enemy *h = e->link("D");
    cout<< e->field("Name")<<endl;
    cout<< h->field("Name")<<endl;
  }
  catch (const runtime_error &err){
    cout << "test37 passed, runtime_error = " << err.what() <<endl;
  }
}
