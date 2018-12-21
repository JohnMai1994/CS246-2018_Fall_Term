#include "coop.h"

Coop::Coop(int numCourses): Student(numCourses) {}

int Coop::getFees() { return numCourses * 800; }

