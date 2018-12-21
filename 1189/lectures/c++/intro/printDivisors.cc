#include <iostream>
using namespace std;

void printDivisors(int n) {
  for (int i=1; i <= n; ++i) {
    if (n % i != 0) { // not a divisor
      continue;
    }
    cout << i << endl;
  }
}

int main () {
  int n;
  cin >> n;
  printDivisors(n);
}
