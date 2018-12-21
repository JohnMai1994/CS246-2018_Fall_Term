#include <iostream>
#include <cmath>
using namespace std;

class Vector {
 public:
  int x, y;
  Vector(int x, int y): x{x}, y{y} {}
  int supNorm() { return max(abs(x), abs(y)); }
};

class Vector2 {
 public:
  int x, y;
  Vector2(int x, int y): x{x}, y{y} {}
  virtual int supNorm() { return max(abs(x), abs(y)); }
};

int main() {
  Vector v{1,2};
  Vector2 w{1,2};

  cout << sizeof(v) << " " << sizeof(w) << endl;
}
