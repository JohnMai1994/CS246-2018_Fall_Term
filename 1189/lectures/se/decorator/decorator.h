#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "pizza.h"

class Decorator: public Pizza {
 protected:
  Pizza *component;
 public:
  Decorator(Pizza *component);
  virtual ~Decorator();
};

#endif
