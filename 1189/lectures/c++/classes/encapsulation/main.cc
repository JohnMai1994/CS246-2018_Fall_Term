#include <iostream>
#include "list.h"
using namespace std;

int main() {
  List l;
  l.addToFront(1);
  l.addToFront(2);
  l.addToFront(3);

  for (int  i = 0; i < 3; ++i) {
    cout << l.ith(i) << endl;
  }
}
