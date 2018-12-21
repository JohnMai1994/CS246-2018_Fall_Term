#include <iostream>
#include "listiter.h"
#include "arrayiter.h"
#include "foreach.h"
using namespace std;

int main() {
  List<int> l;
  l.addToFront(1);
  l.addToFront(2);
  l.addToFront(3);

  Array<int> a;
  a.insert(10);
  a.insert(20);
  a.insert(30);

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

  for (auto &n : a) {
    cout << n << endl;
  }

  for_each(l.begin(), l.end(), [](int &n){ cout << n << endl; });
  for_each(a.begin(), a.end(), [](int &n){ cout << n << endl; });
}
