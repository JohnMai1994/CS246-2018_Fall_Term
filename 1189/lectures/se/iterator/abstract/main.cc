#include <iostream>
#include "listiter.h"
using namespace std;

int main() {
  List l;
  l.addToFront(1);
  l.addToFront(2);
  l.addToFront(3);

  for (auto it = l.begin(); it != l.end(); ++it) {
    cout << *it << endl;
  }

  cout << endl;

  for (auto &n : l) {
    ++n;
    cout << n << endl;
  }

  cout << endl;

  for (auto n : l) {
    cout << n << endl;
  }
}
