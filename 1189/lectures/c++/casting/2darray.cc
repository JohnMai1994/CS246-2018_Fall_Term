#include <iostream>
using namespace std;

int main() {
  int (*a)[10] = reinterpret_cast<int(*)[10]> (new int [10*15]);

  for (int i = 0; i < 15; ++i) {
    for (int j = 0; j < 10; ++j) {
      a[i][j] = i * j;
    }
  } 

  for (int i = 0; i < 15; ++i) {
    for (int j = 0; j < 10; ++j) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  delete [] (reinterpret_cast<int*>(a));
}
