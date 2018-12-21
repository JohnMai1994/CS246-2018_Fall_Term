#include <iostream>
#include <iomanip>
using namespace std;

int main () {
  int i = 95;
  cout << hex << i << endl;
  cout << i << endl;
  float price = 2.00;
  cout << fixed << showpoint << setprecision(2) << price << endl;
}
