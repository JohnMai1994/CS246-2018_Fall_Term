#include "topping.h"
#include <string>
using namespace std;

Topping::Topping(string topping, Pizza *component):
 Decorator{component}, theTopping{topping}, thePrice{0.75} {}

float Topping::price() { return component->price() + thePrice; }

string Topping::description() {
 return component->description() + " with " + theTopping;
}

