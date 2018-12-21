#include <iostream>
using namespace std;

class AClass {
 public:
  int a, c;
  AClass(): a{100}, c{300} {}
  virtual int f (){ return a+1; }
};

class B: public AClass{
 public:
  int b, d;
  B(): AClass(), b{200}, d{400} {}
  virtual int g(){ return b-1; }
};

int main () {
  AClass a;
  B b;

  int *pa = reinterpret_cast<int*>(&a);
  int *pb = reinterpret_cast<int*>(&b);

  for (int i = 0; i < sizeof(a)/sizeof(int); ++i) cout << pa[i] << endl;
  cout << endl;
  for (int i = 0; i < sizeof(b)/sizeof(int); ++i) cout << pb[i] << endl;
}
