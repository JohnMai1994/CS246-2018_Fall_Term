#ifndef _COUNT_H_
#define _COUNT_H_
#include "textprocess.h"
#include <string>
#include <iostream>

class Count: public TextProcessor{
      char c;
      int count;
      TextProcessor * tp;
      
      public:
         Count(char character, int count, TextProcessor * TP);
         ~Count();
         void setSource(std::istream *input);
         std::string getWord();


};



#endif
