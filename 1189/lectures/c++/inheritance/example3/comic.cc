#include "comic.h"
#include <string>

using std::string;

Comic::Comic(const string &title, const string &author, int length, const string &hero):
  Book{title, author, length}, hero{hero} {}

bool Comic::isHeavy() const { return getLength() > 30; }
string Comic::getHero() const { return hero; }

