#include "rightHand.h"
#include <vector>
#include "maze.h"
#include <unistd.h>

using namespace std;


RightHand::RightHand(Maze &theMaze) : theMaze{theMaze} {}


Action RightHand::translateDirection(){
  switch ( facing )
  {
    case NORTH: return UP;
    case EAST:  return RIGHT;
    case SOUTH: return DOWN;
    case WEST:  return LEFT;
  }
  return NONE;
}

Dir RightHand::myRight(){
  Dir d = EAST;
  switch ( facing )
  {
    case NORTH: { d = EAST;  break; }
    case EAST:  { d = SOUTH; break; }
    case SOUTH: { d = WEST;  break; }
    case WEST:  { d = NORTH; break; }
  }
  return d;
}

Dir RightHand::myLeft(){
  switch ( facing )
  {
    case NORTH: return WEST;
    case EAST:  return NORTH;
    case SOUTH: return EAST;
    case WEST:  return SOUTH;
  }
}

State RightHand::checkMyRight(){
  return theMaze.checkDir(myRight());
}

bool RightHand::canMove(State s){
  return s == EMPTY || s == GOAL;
}

void RightHand::turn(){
  State toMyRight = checkMyRight();
  
  if ( canMove(toMyRight) ){
    facing = myRight();
    return;
  }
  State ahead = theMaze.checkDir(facing);
  // check ahead of me
  while ( ! canMove(ahead) ){
    facing = myLeft();
    ahead = theMaze.checkDir(facing);
  } 
}

Action RightHand::moveForward(){
  return translateDirection();
}

Action RightHand::action() {
  usleep(100000);
  turn();
  return moveForward();
};
