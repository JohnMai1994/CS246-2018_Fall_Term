#include <iostream>

class X {
  int *x;
 public:
  X(int n): x{new int [n]} {}
  ~X() { delete [] x; }
};

class Y: public X {
  int *y;
 public:
  Y(int n, int m): X{n}, y{new int [m]} {}
  ~Y() { delete [] y; }
};

// Run with valgrind
int main () {
  X x{5};
  Y y{5, 10};

  X *xp = new Y{5, 10};

  delete xp;
}
