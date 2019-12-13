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
    Enemy *h = e->link("D");
    cout<< e->field("Name")<<endl;
    cout<< h->field("Name")<<endl;
  }
  catch (...) {
    cout<< e->link("Henchman")->field("Name")<<endl;
    cout<< e->field("Name")<<endl;
  }
}
