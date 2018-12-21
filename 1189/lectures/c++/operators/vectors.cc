#include <iostream>
using namespace std;

struct Vec {
  int x;
  int y;
};

Vec operator+(const Vec &v1, const Vec &v2) {
  Vec v {v1.x + v2.x, v1.y + v2.y};
  return v;
}

Vec operator*(const Vec &v1, const int k) {
  return {k * v1.x, k * v1.y};
}

Vec operator*(const int k, const Vec &v1) {
  return v1 * k;
}

/*
void operator=(Vec &v1, const Vec &v2){
  v1.x = v2.x;
  v1.y = v2.y
}
*/   // how to define += this operator???
int main () {
  Vec v1 {1, 2};
  Vec v2 {3, 4};
  Vec v3 {v1 + v2};
  Vec v4 {2 * v1};
  Vec v5 {v2 * 3};
  Vec v6 {(v4 *3)+(2 * v5)};

  cout << "v3.x = " << v3.x << "   v3.y = " << v3.y << endl;
  cout << "v4.x = " << v4.x << "   v4.y = " << v4.y << endl;
  cout << "v5.x = " << v5.x << "   v5.y = " << v5.y << endl;
  cout << "v6.x = " << v6.x << "   v6.y = " << v6.y << endl;
  Vec v1 += v2;
  cout << v1.x << "  " << v1.y << endl;
}
