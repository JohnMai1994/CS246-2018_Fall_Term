#include "double.h"
using namespace std;

DoubleWords::DoubleWords(int doub_time, string prev, TextProcessor *TP): doub_time(doub_time), prev(prev), tp(TP) {};

DoubleWords::~DoubleWords() {delete tp;}

void DoubleWords::setSource(istream * input) {
     tp->setSource(input);
}

string DoubleWords::getWord() {
     string s;
     if (doub_time % 2 == 1) {
        s = prev;
     } else {
        s = tp -> getWord();
        prev = s;
     }
     doub_time += 1;
     return s;

}

