#ifndef __TEXTPROCESS_H__
#define __TEXTPROCESS_H__
#include <iostream>
#include <string>

class TextProcessor {
  public:
    virtual void setSource(std::istream *inp) = 0;
    virtual std::string getWord() = 0;
    virtual ~TextProcessor();
};

#endif
