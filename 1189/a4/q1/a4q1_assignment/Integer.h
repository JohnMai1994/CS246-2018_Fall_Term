#ifndef _INTEGER_H_
#define _INTEGER_H_
#include <string>
#include "Expr.h"


class Integer: public Expr{
    int num;
    public:
      Integer(int num);
      void prettyprint() const ;
      int evaluate() const ;
      void set(std::string a, int value);
      void unset(std::string a);
      ~Integer();
};

#endif
