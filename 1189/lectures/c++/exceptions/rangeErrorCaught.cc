#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int main () {
  vector<int> v;
  v.emplace_back(2);
  v.emplace_back(4);
  v.emplace_back(6);

  try {
     cout << v.at(3) << endl;  // out of range
  }
  catch (out_of_range r) {
     cerr << "Bad range " << r.what() << endl;
  }

  cout << "Done" << endl;
}
