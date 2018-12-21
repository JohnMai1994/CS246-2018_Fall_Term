#include "text.h"
#include <string>

using namespace std;

Text::Text(const string &title, const string &author, int length, const string &topic):
  Book{title, author, length}, topic{topic} {}

string Text::getTopic() const { return topic; }
