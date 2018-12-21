#ifndef __ECHO_H__
#define __ECHO_H__
#include <iostream>
#include <string>
#include "textprocess.h"

class Echo: public TextProcessor {
    std::istream *source;
    bool failed;
 public:
    Echo();
    void setSource(std::istream *inp);
    std::string getWord() override;
};

#endif
