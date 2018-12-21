#include "maze.h"
#include <iostream>
#include <cstdlib>
#include "standard.h"
#include "writtenView.h"
#include "keyboard.h"
#include "curseControl.h"
#include "curseView.h"
#include "rightHand.h"

Maze::Cell::Cell(int row, int col, State state): row{row}, col{col}, state{state} {}


Maze::Maze(int rows, int cols, bool curses, int computerLevel): Model{rows, cols}, sizeX{cols}, sizeY{rows}{
  srand(time(NULL));
  
  if ( computerLevel > 0 ){
    addController(std::move(std::make_unique<RightHand>(*this)));
  }  

  if ( curses ){
    addView(std::move(std::make_unique<Curses>(cols, rows, *this)));
    if ( !hasController() ){
      addController(std::move(std::make_unique<CurseKeyboard>()));
    }
  } else {
    addView(std::move(std::make_unique<Standard>(cols, rows, *this)));
    addView(std::move(std::make_unique<Written>(cols, rows, *this)));
    if ( !hasController() ){
      addController(std::move(std::make_unique<Keyboard>()));
    }
  }

  for (int i = 0; i < rows; ++i){
    std::vector<Cell> row;
    for (int j = 0; j < cols; ++j){
      row.emplace_back(i, j, State::EMPTY);
    }
    grid.emplace_back(row);
  }
  
  // TODO: Randomly generate walls
   recursiveWalls(0, 0, sizeX-1, sizeY-1); 
  
  int x, y;
  do{
    x = rand() % cols;
    y = rand() % rows;
  } while ( grid[y][x].state != EMPTY );

  goal = &grid[y][x];
  updateCell(y, x, GOAL);
  
  do{
    x = rand() % cols;
    y = rand() % rows;
  } while ( grid[y][x].state != EMPTY );
  
  do{
    x = rand() % cols;
    y = rand() % rows;
  } while ( grid[y][x].state != EMPTY );
  curX = x;
  curY = y;
  
  loc = &grid[y][x];
  updateCell(y, x, PLAYER);
}

bool wallLocation(int n, int acc = 2){
  if ( n == acc - 1) return true;
  if ( acc > n ) return false;
  else return wallLocation(n, acc*2);
}

void Maze::recursiveWalls(int x0, int y0, int x1, int y1, int dir){
  if ( x1 - x0 < 2 || y1 - y0 < 2 || x0 > x1 || y0 > y1 ) return;
//  int dir = rand() % 2;
  if ( x1 - x0 < 2 ) dir = 1;
  if ( y1 - y0 < 2 ) dir = 0;
  int w0 = dir == 0 ? x0 : y0;
  int w1 = dir == 0 ? x1 : y1;
  int not0 = dir == 0? y0 : x0;
  int not1 = dir == 0? y1 : x1;
  int wall = ( w1 - w0 )/2;
  int wallLoc = wall + w0;
  int wallLen = ( not1 - not0 + 1 );
  if ( wallLen <= 1 ) return;
  int missing = ( rand() % wallLen ) + not0;
  if ( wallLocation(missing-not0) ) ++missing;
  for ( int i = not0; i < wallLen + not0; ++i ){
    if ( i != missing ) updateCell(dir == 0? wallLoc: i, dir==0?i:wallLoc, WALL);
  }
  recursiveWalls(x0, y0, dir==0?wallLoc-1:x1, dir==0?y1:wallLoc-1,dir?0:1);
  recursiveWalls(dir==0?wallLoc+1:x0, dir==0?y0:wallLoc+1,x1,y1,dir?0:1);
}

void Maze::updateCell(int row, int col, State s){
  grid[row][col].state = s;
  updateViews(row, col, s);
}

State Maze::getState(int row, int col) {
  if ( col < 0 || col >= sizeY || row < 0 || row >= sizeX ) return WALL;
  return grid[col][row].state;
}

State Maze::checkDir(Dir d){
  int x = loc->col;
  int y = loc->row;
  switch ( d ){
    case NORTH: return getState(x, y - 1);
    case EAST:  return getState(x + 1, y);
    case SOUTH: return getState(x, y + 1);
    case WEST:  return getState(x - 1, y);
  }
}


void Maze::play(){
  int newX = curX, newY = curY;
  Action a;
  while(std::cin){
    displayViews();
    a = getAction();
    if ( NONE == a ) continue;
    if ( UP == a ) {
      newY -= 1;
    } else if ( DOWN == a ){
      newY += 1;
    } else if ( RIGHT == a ){
      newX += 1;
    } else if ( LEFT == a ){
      newX -= 1;
    } else if ( INVALID == a ){
      updateViews("I'm sorry, that is incorrect.");
      continue;
    }
    if ( newY < 0 || newY >= sizeY || newX < 0 || newX >= sizeX ){
      newY = curY;
      newX = curX;
      updateViews("I'm sorry, that is incorrect.");
      continue;
    }
    State newCell = grid[newY][newX].state;
    if ( newCell == WALL || newCell == PLAYER ){
      newY = curY;
      newX = curX;
      updateViews("I'm sorry, that is incorrect.");
      continue; 
    } else if ( newCell == EMPTY ){
      updateCell(curY,curX,EMPTY);
      updateCell(newY,newX,PLAYER);
      curY = newY;
      curX = newX;
      loc = &grid[curY][curX];
      updateViews("");
    } else if ( newCell == GOAL ){
      updateViews("You reached the goal. You win! Huzzah!");
      break;
    }
  }
}
