#include "dropfirst.h"

using namespace std;

DropFirst::DropFirst(int num, TextProcessor * TP): n(num), tp(TP) {}

void DropFirst::setSource(istream *input) {
     tp->setSource(input);
}

string DropFirst::getWord(){
       string s;
       s = tp->getWord();
       int size = s.length();
       if (size <= n) {
          return getWord();
       } else {
          s = s.substr(n);
          return s;
       }
} 

DropFirst::~DropFirst() { delete tp;}


