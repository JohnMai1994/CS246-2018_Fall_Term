#ifndef _VARIABLE_H_
#define _VARIABLE_H_
#include <string>
#include "Expr.h"

class Variable: public Expr{
    std::string name;
    bool flag;
    int num;
    public:
      Variable(std::string name, bool flag, int num);
      void prettyprint() const ;
      int evaluate() const ;
      void set(std::string a, int value);
      void unset(std::string a);
      ~Variable();
      // q2
//      Variable &operator= (const Variable &other);
      Variable (const Variable &other);
      Variable * copy() const;
};

#endif
