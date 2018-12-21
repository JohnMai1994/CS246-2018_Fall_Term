#include <iostream>
#include "studentStatFun.h"
using namespace std;

int main () {
  Student billy(60, 70, 80);
  Student bobby(70, 80, 90);

  cout << "Number of instances: ";
  Student::printNumInstances();
}
