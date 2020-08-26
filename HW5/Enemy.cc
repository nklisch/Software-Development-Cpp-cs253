#include "Enemy.h"
#include "Gallery.h"

using namespace std;

Enemy::Enemy(const string& keyfile)
{
  ifstream input(keyfile);
  if (!input.is_open())
    throw runtime_error("Keyfile: " + keyfile + " failed to open.");
  readKeyFile(input, validKeys);
  myGallery = nullptr;
}

Enemy::Enemy(const string& keyfile, Gallery * g)
{
  ifstream input(keyfile);
  if (!input.is_open())
    throw runtime_error("Keyfile: " + keyfile + " failed to open.");
  readKeyFile(input, validKeys);
  myGallery = g;
}

bool Enemy::read(istream &input)
{
  clear();
  string key;
  string value;
  string line;
  
  removeBlankLines(input,line);
  
  if (isspace(line[0]))
    throw runtime_error("The key is missing for the line: " + line);

  while (input && !isBlankLine(line))
  {
    readKey(line, key);
    readValue(input, line, value);
    add(key, value);
    value.clear();
    key.clear();
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
  if (showName && name.key().length() > maxLength)
    maxLength = name.key().length();
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
  EnemyProperty ep = find(key);
  if (ep.empty())
    throw range_error("Key " + key + " not found");
  return ep.value();
}

void Enemy::clear()
{
  name.clear();
  others.clear();
  links.clear();
  maxLinksLength = 0;
  maxOthersLength = 0;
  mySize = 0;
}

void Enemy::writeName(ostream &out, int maxLength) const
{
  out << setw(maxLength + 1);
  out << name.key() << name.value() << "\n";
}

void Enemy::writeLinks(ostream &out, int maxLength) const
{
  for (auto &l : links)
  {
    out << setw(maxLength + 1);
    out << l.key() << l.value() << "\n";
  }
}

void Enemy::writeOthers(ostream &out, int maxLength) const
{
  for (auto &o : others)
  {
    out << setw(maxLength + 1);
    out << o.key() << o.value() << "\n";
  }
}

void Enemy::add(const string &key, const string &value)
{
  EnemyProperty p(key, value);
  if (!isAlphaNum(p.key()))
    throw runtime_error("Key " + p.key() + " is not alphanumeric.");
  if (!validKeys.empty() && !validKeys.contains(p.key()))
    throw runtime_error("The key: " + p.key() + "is not valid it is not in the provided key file");
  if (!isKeyUnique(p))
    throw runtime_error("The key " + p.key() + " is not unique");
  if (p.value().empty())
    throw runtime_error("The value is missing for the key " + p.key());

  if (p.key() == "Name")
  {
    name = p;
    showName = true;
  }
  else if (key.find("Link") != string::npos)
  {
    links.push_back(p);
    if (p.key().length() > maxLinksLength)
      maxLinksLength = p.key().length();
    showLink = true;
  }
  else
  {
    others.push_back(p);
    if (p.key().length() > maxOthersLength)
      maxOthersLength = p.key().length();
    showOther = true;
  }
  mySize++;
}

string Enemy::toString() const
{
  string s(name.key() + " " + name.value());
  for (auto &l : links)
    s += "\n" + l.key() + " " + l.value();
  for (auto &o : others)
    s += "\n" + o.key() + " " + o.value();
  return s;
}

EnemyProperty Enemy::find(const string &key) const
{
  if (key == name.key())
    return name;
  for (auto &p : others)
  {
    if (key == p.key())
      return p;
  }
  for (auto &l : links)
  {
    if (key == l.key())
      return l;
  }
  return EnemyProperty();
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

void Enemy::readKeyFile(istream &input, Keys &k)
{
  string key;
  string line;
  while (getline(input, line))
  {
    key = trim(line);
    if (!line.empty())
    {
      if (isAlphaNum(key))
        k.add(key);
      else
        throw runtime_error("Key " + key + " is not alphanumeric.");
    }
  }
}

Enemy * Enemy::link(const string& relation) const 
{
  if(!myGallery)
    throw runtime_error("The enemy " + name.value() + " does not belong to a gallery");

  EnemyProperty ep = find("Link" + relation); 
  if(ep.empty())
    throw range_error("No link relation of the type " + relation);
    
  for(size_t i = 0; i < myGallery->size(); i++){
    if(myGallery->get(i)->getName() == ep.value())
      return myGallery->get(i);
    }
  throw range_error("No enemy in this gallery is related by " + relation);
  return nullptr;
}

ostream &operator<<(ostream &out, const Enemy &e)
{
  e.write(out);
  return out;
}


