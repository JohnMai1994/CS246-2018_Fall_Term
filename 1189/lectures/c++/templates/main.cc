#include <iostream>
#include "listiter.h"
using namespace std;
#include <string>

int main() {
  List<int> l;
  l.addToFront(1);
  l.addToFront(2);
  l.addToFront(3);

  List<string> w;
  w.addToFront("I ");
  w.addToFront("Love ");
  w.addToFront("You!!");

  for (auto it = w.begin(); it != w.end(); ++it) {
    cout << *it << endl;
  }
  
  cout << endl;

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
