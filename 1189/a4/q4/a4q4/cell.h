#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include "window.h"

const int maxNeighbours = 8;

class Cell {
  bool isAlive;
  int numNeighbours;
  int Live;
  Cell *neighbours[maxNeighbours];
  // this part is for window
  int x,y, width, height;
  Xwindow * window;

  // this part is for window
  void add_Live();

  // Add other private members if necessary

 public:
  Cell();  // Default constructor
  ~Cell(); // Destructor

  void setLiving();         // Explicitly sets me to living.

  void addNeighbour(Cell *neighbour);  // Adds a pointer to one of my
                            // neighbours to my array.

  void neighbourIsAlive();  // My neighbours will call this, to let me know
                            // they're alive.

  void alertNeighbours();   // Tell all of my neighbours that I am alive
                            // (if I'm alive).

  void recalculate();       // Reassess my living-or-dead status, based on
                            // info from neighbours.

  friend std::ostream&::operator<<(std::ostream &out, const Cell &c);

  // this part is for window
  void setCoords(int x, int y, int width, int height, Xwindow * Xw);
  void draw();
  void undraw();

  // this part is for window
};


#endif
