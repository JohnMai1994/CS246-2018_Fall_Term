#include <iostream>
#include <sstream>
using namespace std;

int main () {
  string s;
  while (cin >> s) {
    istringstream ss{s};
    int n; 
    if (ss >> n) cout << n << endl;
  }
}
