#include "regular.h"

Regular::Regular(int numCourses): Student(numCourses) {}

int Regular::getFees() { return numCourses * 700; }

