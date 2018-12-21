#ifndef ___MAZE__H___
#define ___MAZE__H___

#include "model.h"
#include "state.h"
#include <vector>

class Maze: public Model{
  struct Cell{
    const int row, col;
    State state;
    Cell(int, int, State s = State::EMPTY);
  };
 
  std::vector<std::vector<Cell>> grid;
  Cell* goal;
  Cell* loc;
  int curX, curY;
  int sizeX, sizeY;

  void updateCell(int row, int col, State s = EMPTY);

  void recursiveWalls(int, int, int, int, int dir = 0);
 public:

  Maze(int row, int col, bool curses, int computerLevel);

  State getState(int row, int col);
  State checkDir(Dir d);  

  void play();
};

#endif
