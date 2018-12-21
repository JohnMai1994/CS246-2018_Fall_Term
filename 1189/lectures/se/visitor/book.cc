#include <string>
#include "BookVisitor.h"
#include "book.h"

using namespace std;

Book::Book(const string &title, const string &author, int length):
  title{title}, author{author}, length{length} {}

int Book::getLength() const { return length; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
bool Book::isHeavy() const { return length > 200; }

// My favourite books are short books.
bool Book::favourite() const { return length < 100; }

void Book::accept(BookVisitor &v) { v.visit(*this); }

Book::~Book(){}
