#ifndef __CURSES_VIEW___H__
#define __CURSES_VIEW___H__

#include "view.h"
#include <vector>
#include <iostream>
#include <map>
#include "state.h"

class Maze;

class Curses: public View{
  int width;
  int height;
  Maze& model;
  std::map<State, char> displayMap;
 public:
  Curses(int row, int col, Maze& m);
  ~Curses();
  void update(const std::string& msg) override;
  void update(int row, int col, State state) override;
  void updateView() override;
};
#endif
