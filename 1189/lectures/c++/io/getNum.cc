#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main () {
  int n;
  while (true) {
    cout << "Enter a number:" << endl;
    string s;
    cin >> s;
    istringstream ss{s};
    if (ss >> n) break;
    cout << "I said, ";
  }
  cout << "You entered " << n << endl;
}
