#include <string>
#include "book.h"

using namespace std;

Book::Book(const string &title, const string &author, int length):
  title{title}, author{author}, length{length} {}

string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
int Book::getLength() const { return length; }
bool Book::isHeavy() const { return length > 200; }
