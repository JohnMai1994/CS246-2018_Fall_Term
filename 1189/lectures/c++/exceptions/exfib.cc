#include <iostream>
using namespace std;

void fib(int n) {
  if (n == 0) throw 0;
  if (n == 1) throw 1;
  try {
    fib(n-1);
  }
  catch (int a) {
    try {
      fib(n-2);
    }
    catch (int b) {
      throw (a + b);
    }
  }
}

int main() {
  int n;
  while (cin >> n) {
    try {
      fib(n);
    }
    catch (int m) {
      cout << m << endl;
    }
  }
}

