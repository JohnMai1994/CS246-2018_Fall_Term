#ifndef _DROPFIRST_H_
#define _DROPFIRST_H_
#include <iostream>
#include <string>
#include "textprocess.h"

class DropFirst: public TextProcessor {
      int n;
      TextProcessor * tp;

      public:
      DropFirst(int num, TextProcessor * TP);
      void setSource(std::istream *in);
      std::string getWord();
      ~DropFirst();
};

#endif
