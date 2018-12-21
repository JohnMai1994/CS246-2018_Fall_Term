#ifndef _EXPR_H_
#define _EXPR_H_
#include <string>

class Expr {
    public:
    virtual void prettyprint() const= 0;
    virtual int evaluate() const= 0;
    virtual void set(std::string a, int value) = 0;
    virtual void unset(std::string a) = 0;
    virtual ~Expr() = 0;
};

#endif


