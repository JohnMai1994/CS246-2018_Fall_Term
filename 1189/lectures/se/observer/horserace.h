#ifndef __HORSERACE_H__
#define __HORSERACE_H__
#include <fstream>
#include <string>
#include "subject.h"


class HorseRace: public Subject {
  std::fstream in;
  std::string lastWinner;

 public:
  HorseRace(std::string source);
  ~HorseRace();

  bool runRace(); // Returns true if a race was successfully run.

  std::string getState();
};

#endif
