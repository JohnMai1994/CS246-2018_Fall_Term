#include <iostream>
#include <string>
#include <utility>
#include "book.h"

using namespace std;

Book::Book(const string &title, const string &author, int length):
  title{title}, author{author}, length{length} {}

Book::Book(Book &&b): title{std::move(b.title)}, author{std::move(b.author)}, length{b.length} {
  cout << "Running Book's move ctor... " << endl;
}

int Book::getLength() const { return length; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
bool Book::isHeavy() const { return length > 200; }

// My favourite books are short books.
bool Book::favourite() const { return length < 100; }
