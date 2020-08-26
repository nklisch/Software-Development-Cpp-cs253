//Nathan Klisch
//cs253, Fall2019
//HW1
#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
string prgName;

void printEnemy(const vector<string> &, const vector<string> &, int);
bool isKeyunique(const vector<string> &, const string&);
bool isAlphabetic(const string &);
bool getKey(string &, string &);
bool getValue(string &, string &);
//Finds index of first not blank char, or -1 if not found
int findNotBlankChar(const string &);
//Finds index of first not blank char from the end of string, or -1 if not found
int findNotBlankCharReverse(const string &);
//Finds index of first blank char from start of string of -1 if not found
int findFirstBlankChar(const string &);
bool isBlankLine(const string &);
bool readEnemy(vector<string> &, vector<string> &, string &);
//Gets the length of the longest key
int getMaxCharLength(const vector<string> &);

//Sticking to structs for ease until later
struct Enemy{
	vector<string> keys;
	vector<string> values;
	int maxKeyCharLength;
};


int main(int argc, char *argv[])
{
	prgName = argv[0];
	if(argc > 2)
		return 1;
		
	vector<Enemy> enemyList;
	string line;
	while (getline(cin, line))
	{
		vector<string> keys;
		vector<string> values;	
		if (!isBlankLine(line))
		{
			if (!readEnemy(keys, values, line))
				return 1;
		}
		
		if (!keys.empty())
		{
			Enemy newEnemy;
			newEnemy.maxKeyCharLength = getMaxCharLength(keys);
			newEnemy.keys = keys;
			newEnemy.values = values;
			enemyList.push_back(newEnemy);
		}
		
	}
	if(enemyList.empty())
		return 0;
	for( size_t i = 0; i < enemyList.size() - 1; i++) 
	{
		printEnemy(enemyList[i].keys, enemyList[i].values, enemyList[i].maxKeyCharLength);
		cout << '\n';
	}
	printEnemy(enemyList.back().keys, enemyList.back().values, enemyList.back().maxKeyCharLength);
	return 0;
}

void printEnemy(const vector<string> &keys, const vector<string> &values, int maxKeyCharLength)
{
	for (size_t i = 0; i < keys.size(); i++)
	{
		cout << setw(maxKeyCharLength + 1) << left;
		cout << keys[i] << values[i] << "\n";
	}
}

bool isKeyUnique(const vector<string> &keys, const string &key)
{
	for (const string &k : keys)
	{
		if (key == k)
			return false;
	}
	return true;
}

bool isAlphabetic(const string &key)
{
	for (const auto c : key)
	{
		if (!isalpha(c))
		{
			return false;
		}
	}
	return true;
}

bool getKey(string &key, string &line)
{
	if (isspace(line[0]))
		return false;

	int index = findFirstBlankChar(line);
	if (index > 0)
	{
		key = line.substr(0, index);
		line = line.substr(index, line.length() - 1);
	}
	else
	{
		key = line;
		line.clear();
	}

	return true;
}

bool getValue(string &value, string &line)
{
	int index = findNotBlankChar(line);

	if (index < 0)
		return false;

	int length = findNotBlankCharReverse(line) - index + 1;
	value = line.substr(index, length);
	return true;
}

int findFirstBlankChar(const string &line)
{

	for (size_t i = 0; i < line.size(); i++)
	{
		if (isblank(line[i]))
			return static_cast<int>(i);
	}
	return -1;
}

int findNotBlankChar(const string &line)
{	
	for (size_t i = 0; i < line.length(); i++)
	{
		if (!isspace(line[i]))
		{
			return static_cast<int>(i);
		}
	}
	return -1;
}

int findNotBlankCharReverse(const string &line)
{
	int index = -1;
	if (line.empty())
		return -1;

	for (auto i = line.length() - 1; i == 0; i--)
	{
		if (!isspace(line[i]))
		{
			index = static_cast<int>(i);
			break;
		}
	}
	return index;
}

bool isBlankLine(const string &line)
{
	if (findNotBlankChar(line) >= 0)
		return false;

	return true;
}

//Returns true if enemy is read successfully, false if it fails for any reason
bool readEnemy(vector<string> &keys, vector<string> &values, string &line)
{
	do
	{
		string key;
		string value;
		if (isBlankLine(line))
			return true;

		if (!getKey(key, line))
		{
			cerr << prgName << "- A Key is missing on line:  " << line << "\n";
			return false;
		}
		if (!isAlphabetic(key))
		{
			cerr << prgName << "- Key:" << key << " not alphabetic!" << "\n";
			return false;
		}
		if (!getValue(value, line))
		{
			cerr << prgName << "- Value is missing for Key: " << key << "\n";
			return false;
		}
		if (!isKeyUnique(keys, key))
		{
			cerr << prgName << "- Key: " << key << " is not unique!" << "\n";
			return false;
		}

		keys.push_back(key);
		values.push_back(value);
	} while (getline(cin, line));
	return true;
}

int getMaxCharLength(const vector<string> &keys)
{
	if (keys.empty())
		return 0;

	size_t length = 0;
	for (const auto &k : keys)
	{
		if (k.length() > length)
			length = k.length();
	}
	return static_cast<int>(length);
}
