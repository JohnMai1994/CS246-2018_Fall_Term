#include "grid.h"
#include "window.h"
using namespace std;

Grid::Grid(): size(0), theGrid(), theWindow(nullptr){}

void Grid::clearGrid() {
   theGrid.clear();
}


Grid::~Grid() {
  delete theWindow;
}

void Grid::init(int n){
  this->clearGrid();
  size = n;
  theGrid.resize(size);
  if(theWindow == nullptr) {
     theWindow = new Xwindow;
  }
  
  int d = 500/ size;
  for (int i = 0; i < size; ++i) {
     theGrid[i].resize(size);
     for (int j = 0; j < size; ++j) {
        theGrid[i][j] = Cell();
        theGrid[i][j].setCoords(j*d,i*d,d,d,theWindow);
     }
  }
/*
  for (int i = 0; i < size; ++ i) {
     for (int j = 0; j < size; ++ j){
        int up = i - 1;
        int down = i + 1;
        int left = j - 1;
        int right = j + 1;
        for (int x = up; x < down; ++x) {
           for (int y = left; y < right; ++y) {
              if ((y >= 0) && (x >= 0) && (y <= size) && (x <= size) && ((x!=i)&&(y!=j))){
                theGrid[i][j].addNeighbour(&theGrid[x][y]);
              }
           }
        }
     }
  }
*/

 
  for (int i = 0; i < size; ++i) {
     for (int j = 0; j < size; ++j) {
        if ((i == 0)&&(j == 0)) {
           theGrid[i][j].addNeighbour(&theGrid[i][j+1]);
	   theGrid[i][j].addNeighbour(&theGrid[i+1][j]);
  	   theGrid[i][j].addNeighbour(&theGrid[i+1][j+1]);

        } else if ((i == 0)&&(j+1 >= size)) {
           theGrid[i][j].addNeighbour(&theGrid[i][j-1]);
	   theGrid[i][j].addNeighbour(&theGrid[i+1][j-1]);
  	   theGrid[i][j].addNeighbour(&theGrid[i+1][j]);

        } else if ((i+1 >= size)&&(j+1 >= size)) {
           theGrid[i][j].addNeighbour(&theGrid[i-1][j-1]);
	   theGrid[i][j].addNeighbour(&theGrid[i][j-1]);
  	   theGrid[i][j].addNeighbour(&theGrid[i-1][j]);

        } else if ((i+1 >= size)&&(j == 0)) {
           theGrid[i][j].addNeighbour(&theGrid[i-1][j]);
	   theGrid[i][j].addNeighbour(&theGrid[i-1][j+1]);
  	   theGrid[i][j].addNeighbour(&theGrid[i][j+1]);

        } else if (i == 0) {
           theGrid[i][j].addNeighbour(&theGrid[i][j-1]);
	   theGrid[i][j].addNeighbour(&theGrid[i][j+1]);
  	   theGrid[i][j].addNeighbour(&theGrid[i+1][j]);
           theGrid[i][j].addNeighbour(&theGrid[i+1][j-1]);
	   theGrid[i][j].addNeighbour(&theGrid[i+1][j+1]);

        } else if (i+1 >= size) {
	              
           theGrid[i][j].addNeighbour(&theGrid[i-1][j-1]);
	   theGrid[i][j].addNeighbour(&theGrid[i-1][j]);
  	   theGrid[i][j].addNeighbour(&theGrid[i-1][j+1]);
           theGrid[i][j].addNeighbour(&theGrid[i][j-1]);
	   theGrid[i][j].addNeighbour(&theGrid[i][j+1]);

        } else if (j == 0) {
           theGrid[i][j].addNeighbour(&theGrid[i-1][j+1]);
	   theGrid[i][j].addNeighbour(&theGrid[i+1][j+1]);
  	   theGrid[i][j].addNeighbour(&theGrid[i][j+1]);
           theGrid[i][j].addNeighbour(&theGrid[i-1][j]);
	   theGrid[i][j].addNeighbour(&theGrid[i+1][j]);

        } else if (j+1 >= size) {
           theGrid[i][j].addNeighbour(&theGrid[i-1][j-1]);
	   theGrid[i][j].addNeighbour(&theGrid[i+1][j-1]);
  	   theGrid[i][j].addNeighbour(&theGrid[i][j-1]);
           theGrid[i][j].addNeighbour(&theGrid[i+1][j]);
	   theGrid[i][j].addNeighbour(&theGrid[i-1][j]);

        } else {
           theGrid[i][j].addNeighbour(&theGrid[i-1][j-1]);
	   theGrid[i][j].addNeighbour(&theGrid[i-1][j+1]);
  	   theGrid[i][j].addNeighbour(&theGrid[i-1][j]);
           theGrid[i][j].addNeighbour(&theGrid[i][j-1]);
	   theGrid[i][j].addNeighbour(&theGrid[i][j+1]);
           theGrid[i][j].addNeighbour(&theGrid[i+1][j-1]);
	   theGrid[i][j].addNeighbour(&theGrid[i+1][j+1]);
  	   theGrid[i][j].addNeighbour(&theGrid[i+1][j]);

        }
     }
  }

}


void Grid::tick() {
  
  for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
         //cout << "i is " << i << " j is " << j << endl;
         theGrid[i][j].alertNeighbours();
      }
  }
  //cout << "***"<< endl;
  for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
         theGrid[i][j].recalculate();
         
      }
  }

}

void Grid::turnOn(int i, int j) {
  if ((i > size)|| (j > size)) {
     cerr << "Hey, i or j is out of range" << endl;
     return;
  }

  // alert i, j should in the size
  theGrid[i][j].setLiving();
} 


ostream&operator<<(ostream &out, const Grid &g) {
   for (int i = 0; i < g.size; ++i) {
       for (int j = 0; j< g.size; ++j) {
          out << g.theGrid.at(i).at(j);
       }
       out << endl;
   }
   //cout << "you did it" << endl;
   return out;
}
