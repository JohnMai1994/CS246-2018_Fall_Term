#include <iostream>
#include "studentStatFun.h"
using namespace std;

float Student::computeGrade() const {
    return assigns * 0.4 + mt * 0.2 + final * 0.4;
}

Student::Student(int assigns, int mt, int final):
     assigns(assigns), mt(mt), final(final) {
  ++numInstances;
}

Student::Student(const Student &other): assigns(other.assigns),
                                        mt(other.mt),
                                        final(other.final) {
  ++numInstances;
}

void Student::printNumInstances() {
  cout << numInstances << endl;
}

int Student::numInstances = 0;
