#include "stuffedcrust.h"
#include <string>
using namespace std;

StuffedCrust::StuffedCrust(Pizza *p): Decorator{p} {}

float StuffedCrust::price() { return component->price() + 2.69; }

string StuffedCrust::description() {
 return component->description() + " with stuffed crust";
}

