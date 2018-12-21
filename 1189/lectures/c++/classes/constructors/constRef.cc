#include <iostream>
using namespace std;

struct MyStruct {
  const int myConst = 5;
  int z;
  int &myRef = z;
};

int main () {
}

