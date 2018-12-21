#include <iostream>
using namespace std;

int main () {
  int i;
  while (true) {
    if (!(cin >> i)) {
      if (cin.eof()) break;
      else {
        cin.clear();
        cin.ignore();
      }
    }
    else {
      cout << i << endl;
    }
  }
}
