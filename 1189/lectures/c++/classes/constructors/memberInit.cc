#include <iostream>
using namespace std;

struct MyStruct {
  const int myConst;
  const int &myRef;

  MyStruct(int c, int &r): myConst {c}, myRef {r} {}
};

int main() {
  int z = 5;
  MyStruct m{10, z};

  cout << "m.myConst = " << m.myConst << "  m.myRef = " << m.myRef << endl;
}

