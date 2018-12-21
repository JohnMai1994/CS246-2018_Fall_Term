#ifndef __WRITTEN___H__
#define __WRITTEN___H__

#include "view.h"
#include <vector>
#include <iostream>
#include <map>
#include "state.h"

class Maze;

class Written: public View{
  std::ostream& out;
  int rows, cols;
  int locX = 0, locY = 0;

  Maze& maze;
  void compareDir(int, int, int);
 public:
  Written(int row, int col, Maze& m);
  void update(const std::string& msg) override;
  void update(int row, int col, State state) override;
  void updateView() override;
};
#endif
