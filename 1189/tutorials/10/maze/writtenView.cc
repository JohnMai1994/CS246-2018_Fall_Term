#include "writtenView.h"
#include <iostream>
#include "maze.h"

Written::Written(int row, int col, Maze& m): out{std::cout}, rows{row}, 
    cols{col}, maze{m} {} 

void Written::update(const std::string& msg) {}

void Written::update(int row, int col, State state){
  if ( state == PLAYER ){
    locX = col;
    locY = row;
  }
}

void Written::compareDir(int x, int y, int dir){
  std::string compass;
  if ( dir == 0 ) compass = "north";
  if ( dir == 1 ) compass = "east";
  if ( dir == 2 ) compass = "south";
  if ( dir == 3 ) compass = "west";
  
  out << "To the " << compass << " you see ";
  if ( x > 0 && x < cols - 1 && y > 0 && y < cols - 1 ){
    if ( maze.getState(y, x) == WALL ){
      out << "a wall.";
    }
    if ( maze.getState(y, x) == GOAL ){
      out << "the goal.";
    }
    if ( maze.getState(y, x) == EMPTY){
      out << "a passage.";
    }
  }
  else out << "a wall.";
  out << std::endl;
}

void Written::updateView(){
  for (int i = 0; i < 4; ++i){
    int x = locX, y = locY;
    if ( i == 0 ) y -= 1;
    if ( i == 1 ) x += 1;
    if ( i == 2 ) y += 1;
    if ( i == 3 ) x -= 1;
    compareDir(x, y, i);
  }
}
