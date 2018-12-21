#include <iostream>
using namespace std;

class C {
  int a[1000000];
};

int main () {
  C *b = new C[10000000];
}

