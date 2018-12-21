#include <iostream>
using namespace std;

void fact(int n) {
  if (n == 0) throw 1;
  try {
    fact(n-1);
  }
  catch (int m) {
    throw (n * m);
  }
}

int main() {
  int n;
  while (cin >> n) {
    try {
      fact(n);
    }
    catch (int m) {
      cout << m << endl;
    }
  }
}

