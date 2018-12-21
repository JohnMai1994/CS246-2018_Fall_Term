#include <iostream>
#include <string>
#include "observer.h"
#include "horserace.h"
#include "bettor.h"

using namespace std;

Bettor::Bettor(HorseRace *hr, std::string name, std::string horse):
  subject{hr}, name{name}, myHorse{horse} {
  subject->attach(this);
}

Bettor::~Bettor() {
  subject->detach(this);
}

void Bettor::notify() {
  string winner = subject->getState();
  cout << name << (winner == myHorse ? " wins!" : " loses.") << endl;
}

