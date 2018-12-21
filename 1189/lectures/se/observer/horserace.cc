#include <iostream>
#include <string>
#include "subject.h"
#include "horserace.h"

using namespace std;

HorseRace::HorseRace(string source): in{source} {
}

HorseRace::~HorseRace() {}

bool HorseRace::runRace() {
  bool result {in >> lastWinner};

  if (result) cout << "Winner: " << lastWinner << endl;

  return result;
}

string HorseRace::getState() {
  return lastWinner;
}

