#ifndef _UNARY_H_
#define _UNARY_H_
#include <string>
#include "Expr.h"


class Unary: public Expr{
    std::string method;
    Expr * part;
    public:
      Unary(std::string method, Expr * part);
      void prettyprint() const;
      int evaluate() const;
      void set(std::string a, int value);
      void unset(std::string a);
      ~Unary();
      // q2
//      Unary &operator= (const Unary &other);
      Unary (const Unary &other);
      Unary * copy() const;
};

#endif
