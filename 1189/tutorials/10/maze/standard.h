#ifndef __STANDARD___H__
#define __STANDARD___H__

#include "view.h"
#include <vector>
#include <iostream>
#include <map>
#include "state.h"

class Maze;

class Standard: public View{
  std::vector<std::vector<char>> display;
  std::ostream& out;

  Maze& maze;
  std::map<State, char> displayMap;
 public:
  Standard(int row, int col, Maze& m);
  void update(const std::string& msg) override;
  void update(int row, int col, State state) override;
  void updateView() override;
};
#endif
