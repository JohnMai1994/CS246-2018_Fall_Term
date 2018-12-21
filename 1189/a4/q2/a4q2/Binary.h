#ifndef _BINARY_H_
#define _BINARY_H_
#include <string>
#include "Expr.h"

class Binary: public Expr{
    std::string method;
    Expr * l_part;
    Expr * r_part;
    public:
      Binary(std::string method, Expr * l_part, Expr * r_part);
      void prettyprint() const ;
      int evaluate() const ;
      void set(std::string a, int value);
      void unset(std::string a);
      ~Binary();
      // q2
     // Binary &operator= (const Binary &other);
      Binary (const Binary &other);
      Binary * copy() const;
};

#endif
