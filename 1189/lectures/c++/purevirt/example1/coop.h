#ifndef __COOP_H__
#define __COOP_H__
#include "student.h"

class Coop: public Student {
  public:
    Coop(int numCourses);

    int getFees();
};

#endif
