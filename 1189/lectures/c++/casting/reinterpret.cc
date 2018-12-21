#include <iostream>
using namespace std;

class C {
  int x;   // private
 public:
  explicit C(int xvalue): x(xvalue) {}

  int getX() const { return x; }
};

class RogueC {
 public:
  int x;
};

int main() {
  C c(10);

  cout << c.getX() << endl;

  RogueC *r = reinterpret_cast<RogueC*>(&c);

  r->x = 20;

  cout << c.getX() << endl;
}

