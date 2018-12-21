#include <iostream>
#include <iomanip>
using namespace std;

int neg(int n) { return -n; }
bool neg(bool b) { return !b; }

int main () {
  cout << neg(3) << " " << boolalpha << neg(true) << endl;
}
