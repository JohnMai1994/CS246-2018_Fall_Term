#include <iostream>
#include <iomanip>
using namespace std;

int main () {
  for (int i=0; i < 50; ++i) {
    cout << dec << setw(5) << i << oct << setw(5) << i << hex << setw(5) << i << endl;
  }
  cout << "it show 1 to 50, from decimalism, octonary, hexadecimal "<< endl;
  cout << "setw(x) x is int, which show how many \" \" ought to be exist" << endl;
}
