#ifndef ___VIEW___H__
#define ___VIEW___H__

#include <string>
#include "state.h"

class View{
 public:
  virtual ~View() = default;
  virtual void update(const std::string& msg) = 0;
  virtual void update(int row, int col, State state) = 0;
  virtual void updateView() = 0;
};

#endif
