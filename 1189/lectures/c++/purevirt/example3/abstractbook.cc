#include <iostream>
#include <string>
#include "abstractbook.h"

using namespace std;

AbstractBook::AbstractBook(const string &title, const string &author, int length):
  title{title}, author{author}, length{length} {}

AbstractBook::AbstractBook(const AbstractBook &b): title{b.title}, author{b.author}, length{b.length} {
  cout << "Running the AbstractBook's copy ctor... " << endl;
}

AbstractBook& AbstractBook::operator=(const AbstractBook &rhs) {
  cout << "AbstractBook assignment operator running ..." << endl;

  if (this == &rhs) return *this;
  title = rhs.title;
  author = rhs.author;
  length = rhs.length;
  return *this;
}

int AbstractBook::getLength() const { return length; }
string AbstractBook::getTitle() const { return title; }
string AbstractBook::getAuthor() const { return author; }
bool AbstractBook::isHeavy() const { return length > 200; }

// My favourite books are short books.
bool AbstractBook::favourite() const { return length < 100; }

AbstractBook::~AbstractBook() {}
