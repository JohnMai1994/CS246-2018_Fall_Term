#ifndef _CRUSTANDSAUCE_H_
#define _CRUSTANDSAUCE_H_
#include <string>
#include "pizza.h"

class CrustAndSauce: public Pizza {
 public:
  float price() override;
  std::string description() override;
};

#endif
