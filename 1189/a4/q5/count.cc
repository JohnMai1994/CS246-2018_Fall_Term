#include "count.h"
#include <sstream>
using namespace std;

Count::Count(char character, int count, TextProcessor * TP): c(character), count(count), tp(TP) {}

Count::~Count() { delete tp;}

void Count::setSource(istream *input) { tp->setSource(input);}

string Count::getWord() {
     string s;
     s = tp->getWord();
     int size = s.length();
     for (int i = 0; i < size; ++i ) {
        if (s[i] == c) {
           count += 1;
           stringstream a;
           a << count;
           s.replace(i, 1, a.str());
        }
     }
     return s;
} 




