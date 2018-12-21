#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <string>
#include "window.h"


class Cell {
  bool isAlive;
  bool blind;
  std::string color;
  Xwindow *window;
  int x;
  int y;
  int width = 25;
  int height = 25;

  public:
  Cell();  // Default constructor
  ~Cell(); // Destructorß
  
    void TurnOn(std::string new_color);
    void TurnOff(std::string new_color);
    void TurnBlind();
    void NotBlind();
    std::string GetColor ();
    
    bool IsAlive();

  void draw(int row, int col, Xwindow * board); 

  friend std::ostream& operator<<(std::ostream &out, const Cell &c);
 

};


#endif
