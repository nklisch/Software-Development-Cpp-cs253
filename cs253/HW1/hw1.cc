#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
string prgName; 

void printEnemy(const vector<string>&,const vector<string>&, int);
bool isKeyunique(vector<string>&, string);
bool isAlphabetic(string);
bool getKey(string&, string&);
bool getValue(string&,string&);
//Finds index of first not blank char, or -1 if not found
int findNotBlankChar(string&);
//Finds index of first not blank char from the end of string, or -1 if not found
int findNotBlankCharReverse(string&);
bool isBlankLine(string&);
bool readEnemy(vector<string>&, vector<string>&, string&);
int getMaxCharLength(vector<string>&);
//Returns true if cin see's a EOF character next
bool isEoI();
//Removes blank lines and sets line to the next non-blank line
void removeBlankLines(string&);

int main(int argc, char *argv[]){
	prgName = argv[0];
	vector<string> keys;
	vector<string> values;
	int maxKeyCharLength = argc;	
	string line;
        removeBlankLines(line);

	while(!isEoI()) {
		if(!readEnemy(keys,values,line))
			return 1;
		maxKeyCharLength = getMaxCharLength(keys);
		printEnemy(keys,values,maxKeyCharLength);
		
		removeBlankLines(line);
		if(isEoI())
			return 0;
		else 
			cout << "\n";
		
		keys.clear();
		values.clear();	
	}
	return 0;

}
bool isEoI(){
	return cin.peek() == EOF;
}

void removeBlankLines(string &line){
	while(cin.peek() != EOF && isBlankLine(line)){
		getline(cin, line);
	}
}
void printEnemy(const vector<string> &keys,const vector<string> &values, int maxKeyCharLength){
	auto i = keys.size();
	for(i = 0; i < keys.size(); i++){
	cout << setw(maxKeyCharLength+1) << left;
	cout << keys[i] << values[i] << "\n";	
	}
}

bool isKeyUnique(vector<string>  &keys,const string key) {
	for(string &k : keys){
	if(key.compare(k) == 0)
		return false;
	}
	return true;
}

bool isAlphabetic(string key){
	for(auto c : key){
		if(c < 'A' || c > 'Z'){
			if(c < 'a' || c > 'z')
				return false;
			}
		}
	return true;

}

bool getKey(string &key, string &line){
	if(line[0] == ' ' || line[0] == '\t')
		return false;
	
	auto index = line.find(' ');
	key = line.substr(0, index);
	line = line.substr(index, line.length() - 1);
	return true;
}

bool getValue(string &value, string &line){
	int index = findNotBlankChar(line);
	
	if(index < 0)
		return false;
	int length = findNotBlankCharReverse(line) - index + 1;
	
	value = line.substr(index,length);
	return true;	
}
int findNotBlankChar(string &line){
	int i = 0;	
	int index = -1;
	for(auto c : line){
		if(c != ' ' && c != '\t'){
		index = i;
		break;
		}
	i++;
	}
	return index;
}

int findNotBlankCharReverse(string &line){
	int index = -1;
	for(int i = line.length() - 1; i >= 0; i--){
		if(line[i] != ' ' && line[i] != '\t'){
		index = i;
		break;
		}
	}
	return index;
}

bool isBlankLine(string &line) {
	if(findNotBlankChar(line) >= 0)
		return false;

	return true;
}

//Returns true if enemy is read succesfully, false if it fails for any reason
bool readEnemy(vector<string> &keys,  vector<string> &
values, string &line){
	string key;
	string value;
	do{
			
		if(!getKey(key, line)) {
		cerr << prgName << "- Key is missing!\n";
		return false;
		}
		if(!isAlphabetic(key)) {
		cerr << prgName << "- Key:" << key << " not alphabetic!\n";
		return false;	
		}
		if(!getValue(value, line)) {
		cerr << prgName << "- Value is missing!\n";
		return false;
		}
		if(!isKeyUnique(keys, key)){
		cerr << prgName << "- Key: " << key << " is not unique!\n";
		return false;
		}
		
		keys.push_back(key);
		values.push_back(value);

		if(isEoI())
			return true;

		getline(cin, line);

	} while(!isBlankLine(line));
	return true;
}

int getMaxCharLength(vector<string> &keys)
{	
	auto length = keys[0].length();
	for(auto &k : keys){
	if(k.length() > length)
		length = k.length();
	}
	return length;
}


