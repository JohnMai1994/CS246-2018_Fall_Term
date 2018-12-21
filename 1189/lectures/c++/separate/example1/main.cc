#include <iostream>
#include "vec.h"

using namespace std;

int main () {
  Vec v = {1,2};
  v = v + v;
  cout << v.x << " " << v.y << endl;
}

