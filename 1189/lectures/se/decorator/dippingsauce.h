#ifndef _DIPPINGSAUCE_H_
#define _DIPPINGSAUCE_H_
#include "pizza.h"
#include "decorator.h"
#include <string>

class DippingSauce: public Decorator {
  std::string flavour;
 public:
  DippingSauce(std::string flavour, Pizza *component);
  float price() override;
  std::string description() override;
};

#endif
