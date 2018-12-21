#include <iostream>
#include "Node.h"
using namespace std;

int main() {
  Node myNode = 4;
  Node myNode2{5, &myNode};

  cout << "myNode2: " << myNode2 << endl;
}
