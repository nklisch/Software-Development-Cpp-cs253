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
  Gallery g("file4","file0");
  Enemy *e = g.get(1);
  try{
    Enemy *h = e->link("whatever");
    cout<< e->field("Name")<<endl;
    cout<< h->field("Name")<<endl;
  }
  catch (const runtime_error &err){
    cout << "test36 passed, runtime_error = " << err.what() <<endl;
  }
}
