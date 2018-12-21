#include "comic.h"
#include <iostream>
#include <string>

using namespace std;

Comic::Comic(const string &title, const string &author, int length, const string &hero):
  Book{title, author, length}, hero{hero} {}

Comic::Comic(const Comic &c): Book{c}, hero{c.hero} {}

Comic& Comic::operator=(const Comic &rhs) {
  cout << "Comic assignment operator running ..." << endl;
  if (this == &rhs) return *this;
  Book::operator=(rhs);
  hero = rhs.hero;
  return *this;
}

bool Comic::isHeavy() const { return getLength() > 30; }
string Comic::getHero() const { return hero; }

// My favourite comic books are Superman comics.
bool Comic::favourite() const { return hero == "Superman"; }
