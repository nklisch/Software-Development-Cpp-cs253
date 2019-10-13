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

void readFileInput(vector<string> &files, vector<Enemy> &enemyList);
void readKey(string &line, string &key);
void readEnemysInput(istream &inFile, vector<Enemy> &enemyList);
Enemy readEnemy(istream &inFile, string &line);
void readKeyFile(ifstream &inFile, Keys &k);
void readstdInput(istream &in, vector<Enemy> &el);
void readValue(istream &input, string &line, string &value);

#endif
