#include <iostream>
using namespace std;

struct Cell {
  int contents;
  Cell(): contents(0) {}
  Cell(int n): contents(n) {}
};

int main () {
  Cell ***grid;

  grid = new Cell**[10];

  for (int i=0; i <= 10; ++i) {
    grid[i] = new Cell*[5];
  }

  for (int k=0; k < 10; ++k)
    for (int j=0; j < 5; ++j)
       grid[j][j] = new Cell(k * j);

  cout << grid[4][3]->contents << endl;

  for (int i = 0; i < 10; ++i) delete grid[i];

  delete [] grid;
}

