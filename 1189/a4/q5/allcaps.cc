#include  "allcaps.h"
using namespace std;

AllCaps::AllCaps(TextProcessor * TP): tp(TP) {}

void AllCaps::setSource(istream *input) { tp->setSource(input); }

string AllCaps::getWord() {
   string s;
   s = tp->getWord();
   int cap = 'A' - 'a';
   int size = s.length();
   for (int i = 0; i < size; ++i) {
     if ((s[i] <= 'z')&&(s[i] >= 'a')) {
        s[i] = s[i] += cap;
     }
   }
   return s;
}

AllCaps::~AllCaps() { delete tp;}





