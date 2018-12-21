#include <iostream>
using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  int i;
  try {
    while (true) {
      cin >> i;
      cout << i << endl;
    }
  }
  catch (ios::failure &) {
  }
}
