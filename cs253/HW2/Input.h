#include <string>
#include <vector>
#include "Enemy.h"

using namespace std;
//Reads input from std Input using
bool readStdInput(vector<Enemy> &enemyList);
bool readFileInput(string &keyFiles, vector<string> &inFiles, vector<Enemy> &enemyList);
bool readKey(string &line, string &key);
bool readStdValue(string &line, string &value);
bool readStdEnemy(Enemy &newEnemy, string &line);
void skipBlankLines(istream &in, string &line);
bool readEnemysFile(ifstream &inFile, vector<string> &keys, vector<Enemy> &enemyList);
bool readEnemyInFile(ifstream &inFile, string &line, vector<string> keys, Enemy &newEnemy);
bool readInfileKey(string &line, const vector<string> &keys, string &key);
bool readKeyFile(istream &inFile, vector<string> &keys);
