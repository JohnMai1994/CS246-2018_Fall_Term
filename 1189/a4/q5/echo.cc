#include <iostream>
#include <string>
#include "echo.h"
using namespace std;

Echo::Echo(): source(0) {}

void Echo::setSource(istream *in) { source = in; }

string Echo::getWord() {
  string s;
  *source >> s;
  return s;
}
