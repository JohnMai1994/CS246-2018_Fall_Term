#include "pizza.h"
#include "decorator.h"

Decorator::Decorator(Pizza *component): component{component} {}

Decorator::~Decorator() { delete component; }
