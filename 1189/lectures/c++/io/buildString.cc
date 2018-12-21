#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main () {
  ostringstream ss;
  int lo {1}, hi {100};
  ss << "Enter a # between " << lo << " and " << hi;
  string s {ss.str()};
  cout << s << endl;
}
