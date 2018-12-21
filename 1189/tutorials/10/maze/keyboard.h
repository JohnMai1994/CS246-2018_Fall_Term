#ifndef ___KEYBOARD___H__
#define ___KEYBOARD___H__

#include "controller.h"
#include <iostream>
#include <string>
#include <memory>
#include <map>

class Keyboard: public Controller{
  std::istream& in;
  std::map<std::string,Action> theMap;
  
  Action action() override;
  void remap(const std::string& oldCmd, std::string& newCmd);
  Action map(const std::string& cmd);
 public:
  Keyboard(std::istream& in = std::cin);
};
#endif
