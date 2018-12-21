#ifndef _PIZZA_H_
#define _PIZZA_H_
#include <string>

class Pizza {
 public:
  virtual float price() = 0;
  virtual std::string description() = 0;
  virtual ~Pizza();
};

#endif
