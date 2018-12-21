#include <iostream>
#include "observer.h"
#include "horserace.h"
#include "bettor.h"

using namespace std;

int main(int argc, char **argv) {
  string raceData = "race.txt";
  if (argc > 1) {
    raceData = argv[1];
  }

  HorseRace hr{raceData};

  Bettor Larry{&hr, "Larry", "RunsLikeACow"};
  Bettor Moe{&hr, "Moe", "Molasses"};
  Bettor Curly{&hr, "Curly", "TurtlePower"};

  int count = 0;
  Bettor *Shemp;

  while(hr.runRace()) {
    if (count == 2)
      Shemp = new Bettor{&hr, "Shemp", "GreasedLightning"};
    if (count == 5) delete Shemp;
    hr.notifyObservers();
    ++count;
  }
}
