#include <iostream>
#include <iomanip>
using namespace std;

bool odd(unsigned int n);

bool even(unsigned int n) {
  if (n == 0) return true;
  else return odd(n - 1);
}

bool odd(unsigned int n) {
  if (n == 0) return false;
  else return even(n - 1);
}

int main() {
  cout << boolalpha << even(3) << " " << even(4) << " "
                    << odd(3) << " " << odd(4) << endl;
}
