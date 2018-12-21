#include "text.h"
#include <string>
#include "BookVisitor.h"

using namespace std;

Text::Text(const string &title, const string &author, int length, const string &topic):
  Book{title, author, length}, topic{topic} {}

bool Text::isHeavy() const { return getLength() > 400; }
string Text::getTopic() const { return topic; }

// My favourite textbooks are C++ books
bool Text::favourite() const { return topic == "C++"; }

void Text::accept(BookVisitor &v) { return v.visit(*this); }

