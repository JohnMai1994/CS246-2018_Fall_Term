#ifndef __STUFFEDCRUST_H__
#define __STUFFEDCRUST_H__
#include "pizza.h"
#include "decorator.h"
#include <string>

class StuffedCrust: public Decorator {
 public:
  StuffedCrust(Pizza *component);
  float price() override;
  std::string description() override;
};

#endif
