#include <string>
#include <vector>
#include "Enemy.h"

using namespace std;
//Reads input from std Input using
bool readStdInput(vector<Enemy> &enemyList);
bool readFileInput(string &keys, vector<string> inFiles, vector<Enemy> &enemyList);
bool readKey(string &line, string &key);
bool readStdValue(string &line, string &value);
bool readStdEnemy(Enemy &newEnemy, string &line);
void skipBlankLines(istream &in, string &line);
