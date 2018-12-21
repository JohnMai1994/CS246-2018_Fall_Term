#include <iostream>
using namespace std;

int main() {
  #ifdef DEBUG
    cout << "setting x=1" << endl;
  #endif
  int x = 1;
  while (x < 10) {
    ++x;
    #ifdef DEBUG
      cout << "x is now " << x << endl;
    #endif
  }
  cout << x << endl;
}
