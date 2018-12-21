#include <iostream>
using namespace std;
/*
   Prints the basic C++ types, together with their sizes, in bits.
   Note:  sizeof operator returns a type's size in bytes; multiply by 8 to
          get the size in bits.
*/

int main () {
  cout << "bool: " << 8 * sizeof(bool) << " bits" << endl;
  cout << "char: " << 8 * sizeof(char) << " bits" << endl;
  cout << "short: " << 8 * sizeof(short) << " bits" << endl;
  cout << "int: " << 8 * sizeof(int) << " bits" << endl;
  cout << "long: " << 8 * sizeof(long) << " bits" << endl;
  cout << "long long: " << 8 * sizeof(long long) << " bits" << endl << endl;

  cout << "float: " << 8 * sizeof(float) << " bits" << endl;
  cout << "double: " << 8 * sizeof(double) << " bits" << endl;
  cout << "long double: " << 8 * sizeof(long double) << " bits" << endl << endl;

  cout << "unsigned char: " << 8 * sizeof(unsigned char) << " bits" << endl;
  cout << "unsigned short: " << 8 * sizeof(unsigned short) << " bits" << endl;
  cout << "unsigned int: " << 8 * sizeof(unsigned int) << " bits" << endl;
  cout << "unsigned long: " << 8 * sizeof(unsigned long) << " bits" << endl;
  cout << "unsigned long long: " << 8 * sizeof(unsigned long long) << " bits" << endl << endl;
}
