#ifndef _ALLCAPS_H_
#define _ALLCAPS_H_
#include <iostream>
#include <string>
#include "textprocess.h"


class AllCaps: public TextProcessor {
    TextProcessor * tp;

    public:
    AllCaps(TextProcessor *TP);
    void setSource(std::istream *input);
    std::string getWord();
    ~AllCaps();

};



#endif
