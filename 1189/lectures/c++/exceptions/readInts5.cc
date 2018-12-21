#include <iostream>
using namespace std;

int main () {
  cin.exceptions(ios::eofbit|ios::failbit);
  int i;
  while (true) {
    try {
      cin >> i;
      cout << i << endl;
    }
    catch (ios::failure &) {
      if (cin.eof()) break;
      cin.clear();
      cin.ignore();
    }
  }
}
