#include <iostream>
using namespace std;

template <typename T> class array2D {
  int rows, cols;
  T *arr;
 public:
  array2D(int rows, int cols): rows(rows), cols(cols), arr(new T[rows * cols]) {}
  T& elementAt(int i, int j) { return arr[i * cols  + j]; }
  ~array2D() { delete [] arr; }
};

int main() {
  array2D<int> a(15, 10);

  for (int i = 0; i < 15; ++i) {
    for (int j = 0; j < 10; ++j) {
      a.elementAt(i, j) = i * j;
    }
  } 

  for (int i = 0; i < 15; ++i) {
    for (int j = 0; j < 10; ++j) {
      cout << a.elementAt(i, j) << " ";
    }
    cout << endl;
  }
}
