#ifndef _DOUBLE_H_
#define _DOUBLE_H_
#include <iostream>
#include <string>
#include "textprocess.h"


class DoubleWords: public TextProcessor{
      int doub_time;
      std::string prev;
      TextProcessor * tp;
      public:
         DoubleWords(int doub_time, std::string prev, TextProcessor * TP);
         ~DoubleWords();
         void setSource(std::istream * input);
         std::string getWord();


};


#endif
