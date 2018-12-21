#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  while (cin >> s) {
    istringstream sock{s};
    int n;
    if (sock >> n) cout << n << endl;
  }
}


