#include "example1_hidden.h"

void crash(int *i) {
  *i = 3;
}

void f(int *i) {
  int *j = i;
  j = sophisticated(j);
  j = complicated(j);
  crash(j);
}

int main(int argc, char **argv) {
  f(&argc);
  return 0;
}
