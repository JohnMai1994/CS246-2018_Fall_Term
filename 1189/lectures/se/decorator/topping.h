#ifndef _TOPPING_H_
#define _TOPPING_H_
#include "pizza.h"
#include "decorator.h"
#include <string>

class Topping: public Decorator {
  std::string theTopping;
  const float thePrice;
 public:
  Topping(std::string topping, Pizza *component);
  float price() override;
  std::string description() override;
};

#endif
