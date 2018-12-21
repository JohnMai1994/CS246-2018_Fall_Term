#ifndef __REGULAR_H__
#define __REGULAR_H__
#include "student.h"

class Regular: public Student {
  public:
    Regular(int numCourses);

    int getFees();
};

#endif
