#include <iostream>
using namespace std;

void inc(int n) {
  n = n + 1;
}

int main () {
  int x {5};
  inc(x);
  cout << x << endl;
}
