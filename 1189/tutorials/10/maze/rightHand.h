#ifndef ___RIGHT_HAND__H__
#define ___RIGHT_HAND__H__

#include "controller.h"
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "state.h"

class Maze;

class RightHand: public Controller{
  Maze& theMaze;

  Dir facing = NORTH;

  Action translateDirection();
  Dir myRight();
  Dir myLeft();
  State checkMyRight();
  bool canMove(State);

  void turn();
  Action moveForward();


  Action getDir(int, int);

  Action action() override;
 public:
  RightHand(Maze&);
};
#endif
