#include "cell.h"
#include "window.h"

using namespace std;

Cell::Cell(): isAlive(false), numNeighbours(0), Live(0), x(0), y(0), width(0), height(0), window(nullptr) {}

Cell::~Cell() { }

void Cell::setLiving() {
   isAlive = true;
   this->draw();
} 

void Cell::addNeighbour(Cell *neighbour){
   neighbours[numNeighbours] = neighbour;
   numNeighbours += 1;
}

void Cell::neighbourIsAlive(){
      // cout << Live << endl;
      Live += 1;
}

void Cell::alertNeighbours() {
   if (isAlive) {
   for (int i = 0; i < numNeighbours; ++i) {
      //cout << "number of Neighbour: "<< numNeighbours << endl;
      if (neighbours[i]){
        
        neighbours[i]->neighbourIsAlive();
      }
    }
  }
}

void Cell::recalculate(){
   if ((isAlive)&&(Live < 2)&&(Live > 3)) {
        isAlive = false;
        undraw();
   } else if ((isAlive)&&(Live<= 3)&&(Live >= 2)){
        isAlive = true;
        draw();
   } else if ((!isAlive)&&(Live == 3)){
        isAlive = true; 
        draw();
   } else {
      isAlive = false;
      undraw();
   }
   Live = 0;
}


ostream &operator<<(ostream &out, const Cell &c) {
     if (c.isAlive) {
         
         out << "X";
     } else {
         
         out << "_";
     }
     return out;
}

void Cell::setCoords(int x, int y, int width, int height, Xwindow * window){
   this->x = x;
   this->y = y;
   this->width = width;
   this->height = height;
   this->window = window;
   
}

void Cell::draw() { window->fillRectangle(x, y, width, height); }

void Cell::undraw() { window->fillRectangle(x, y, width, height, 0); }


