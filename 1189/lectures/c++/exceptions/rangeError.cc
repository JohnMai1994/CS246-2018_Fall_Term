#include <iostream>
#include <vector>
using namespace std;

int main () {
  vector<int> v;
  v.emplace_back(2);
  v.emplace_back(4);
  v.emplace_back(6);

  cout << v.at(3) << endl;  // out of range
}
