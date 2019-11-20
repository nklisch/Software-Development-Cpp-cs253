#include "Enemy.h"
#include "Gallery.h"
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

Enemy::Enemy(const string &keyfile)
{
  ifstream input(keyfile);
  if (!input.is_open())
    throw runtime_error("Keyfile: " + keyfile + " failed to open.");
  readKeyFile(input);
  myGallery = nullptr;
}

Enemy::Enemy(const string &keyfile, Gallery *g)
{
  ifstream input(keyfile);
  if (!input)
    throw runtime_error("Keyfile: " + keyfile + " failed to open.");
  readKeyFile(input);
  myGallery = g;
}

Enemy::Enemy(istream &input)
{
if (!input)
    throw runtime_error("Keyfile Input stream given to enemy failed");
readKeyFile(input);
myGallery = nullptr;
}
Enemy::Enemy (istream &input, Gallery *g)
{
if (!input)
  throw runtime_error("Keyfile Input stream given to enemy failed");

readKeyFile(input);
myGallery = g;
}

bool Enemy::read(istream &input)
{
  clear();
  string line;

  removeBlankLines(input, line);

  if (isspace(line[0]))
    throw runtime_error("The key is missing for the line: " + line);

  while (input && !isBlankLine(line))
  {
    string key;
    string value;
    readKey(line, key);
    readValue(input, line, value);
    add(key, value);
  }

  if (!empty() && !hasName())
    throw runtime_error("The enemy is missing it's name\n" + toString());
  if (empty())
    return false;
  return true;
}

void Enemy::write(const string &filename) const
{
  ofstream output(filename, std::ofstream::out);
  if (!output.is_open())
    throw runtime_error(filename + " failed to open.");
  write(output);
  output.close();
}

void Enemy::write(ostream &out) const
{

  size_t maxLength = 0;
  if (showName && nameSize > maxLength)
    maxLength = nameSize;
  if (showOther && maxOthersLength > maxLength)
    maxLength = maxOthersLength;
  if (showLink && maxLinksLength > maxLength)
    maxLength = maxLinksLength;
  out << left;
  if (showName)
    writeName(out, maxLength);
  if (showOther)
    writeOthers(out, maxLength);
  if (showLink)
    writeLinks(out, maxLength);
}

string Enemy::field(const string &key) const
{
  if(key == "Name")
    return name;
  auto valueI = keyValues.find(key);
  if(valueI == keyValues.end())
    throw range_error("Key " + key + " not found");
  return valueI->second;
}

void Enemy::clear()
{
  name.clear();
  otherKeys.clear();
  linkKeys.clear();
  keyValues.clear();
  maxLinksLength = 0;
  maxOthersLength = 0;
  mySize = 0;
}

void Enemy::writeName(ostream &out, int maxLength) const
{
  out << setw(maxLength + 1);
  out << "Name" << name << "\n";
}

void Enemy::writeLinks(ostream &out, int maxLength) const
{
  for (auto &l : linkKeys)
  {
    out << setw(maxLength + 1);
    out << l << keyValues.at(l) << "\n";
  }
}

void Enemy::writeOthers(ostream &out, int maxLength) const
{
  for (auto &o : otherKeys)
  {
    out << setw(maxLength + 1);
    out << o << keyValues.at(o) << "\n";
  }
}

void Enemy::add(const string &key, const string &value)
{
  if (!isAlphaNum(key))
    throw runtime_error("Key " + key + " is not alphanumeric.");
  if (validKeys.find(key) == validKeys.end())
    throw runtime_error("The key " + key + " is not valid it is not in the provided key file");
  if (!isKeyUnique(key))
    throw runtime_error("The key " + key + " is not unique");
  if (value.empty())
    throw runtime_error("The value is missing for the key " + key);

  if (key == "Name")
  {
    name = value;
    showName = true;
  }
  else if (key.find("Link") != string::npos)
  {
    linkKeys.push_back(key);
    keyValues[key] = value;
    if (key.length() > maxLinksLength)
      maxLinksLength = key.length();
    showLink = true;
  }
  else
  {
    otherKeys.push_back(key);
    keyValues[key] = value;
    if (key.length() > maxOthersLength)
      maxOthersLength = key.length();
    showOther = true;
  }
  mySize++;
}

string Enemy::toString() const
{
  string s("Name " + name);
  for (auto &l : linkKeys)
    s += "\n" + l + " " + keyValues.at(l);
  for (auto &o : otherKeys)
    s += "\n" + o + " " + keyValues.at(o);
  return s;
}

void Enemy::readKey(string &line, string &key)
{
  auto index = findFirstBlankChar(line);
  if (index != string::npos)
  {
    key = line.substr(0, index);
    line = line.substr(index, line.length() - 1);
  }
  else
  {
    key = line;
    line = " ";
  }
}

void Enemy::readValue(istream &input, string &line, string &value)
{
  while (input && isspace(line[0]))
  {
    if (value.empty())
      value = trim(line);
    else
      value += " " + trim(line);
    getline(input, line);
  }
}

void Enemy::readKeyFile(istream &input)
{
  string key;
  string line;
  while (getline(input, line))
  {
    key = trim(line);
    if (!line.empty())
    {
      if (isAlphaNum(key)){
        auto result = validKeys.insert(key);
        if(!result.second)
          throw runtime_error("This key: " + key + " already exists");
      }
      else
        throw runtime_error("Key " + key + " is not alphanumeric.");
    }
  }
}

Enemy *Enemy::link(const string &relation) const
{
  if (!myGallery)
    throw runtime_error("The enemy " + name + " does not belong to a gallery");
  string value;
  try
  {
    value = field("Link" + relation);
  }
  catch (range_error &e)
  {
    throw range_error("No link relation of the type " + relation);
  }

  for (size_t i = 0; i < myGallery->size(); i++)
  {
    if (myGallery->get(i)->getName() == value)
      return myGallery->get(i);
  }
  throw range_error("No enemy in this gallery is related by " + relation);
  return nullptr;
}

bool Enemy::operator==(const Enemy &e) const
{
  if (e.mySize != mySize)
    return false;
  for (const auto &kv : keyValues)
  {
    try
    {
      if (e[kv.first] != kv.second)
        return false;
    }
    catch (const range_error &err)
    {
      return false;
    }
  }
  return true;
}

ostream &operator<<(ostream &out, const Enemy &e)
{
  e.write(out);
  return out;
}

bool Enemy::isKeyUnique(const string &key) const
{
  if(key == "Name" && hasName())
    return false;
  return keyValues.find(key) == keyValues.end();
}

std::pair<string, string> Enemy::operator[](size_t i) const 
{
if(i >= mySize)
    throw range_error("Index " + to_string(i) + " is out of bounds in enemy " + name);
if(i == 0)
  return std::pair<string,string>("Name", name);
else if(i < otherKeys.size() + 1)
  return *keyValues.find(otherKeys[i - 1]);
return *keyValues.find(linkKeys[i - otherKeys.size() - 1]); 
}
