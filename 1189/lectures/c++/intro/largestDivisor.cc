#include <iostream>
using namespace std;

void largestDivisor(int n) {
  for (int i=n-1; i >= 1; --i) {
    if (n % i == 0) { 
      cout << i << endl;
      break;
    }
  }
}

int main () {
  int n;
  cin >> n;
  largestDivisor(n);
}
