#include "comic.h"
#include <string>

using std::string;

Comic::Comic(const string &title, const string &author, int length, const string &hero):
  Book{title, author, length}, hero{hero} {}

string Comic::getHero() const { return hero; }

