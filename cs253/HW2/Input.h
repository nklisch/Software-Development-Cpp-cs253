#ifndef Input_h
#define INput_h

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <iomanip>
#include "Utilities.h"
#include "Error.h"
#include "Enemy.h"
#include "Keys.h"

using namespace std;
//Reads input from std Input using

void readFileInput(vector<string> &files, Keys &validKeys, vector<Enemy> &enemyList);
void readKey(string &line, string &key);
void readEnemysInput(istream &inFile, Keys &validKeys, vector<Enemy> &enemyList);
Enemy readEnemy(istream &inFile, string &line, Keys& validKeys);
Keys readKeyFile(ifstream &inFile, Keys&);
void readstdInput(istream& in, Keys &k, vector<Enemy> &el);

#endif

