#include "cell.h"

using namespace std;

Cell::Cell(): isAlive(false), numNeighbours(0), Live(0) {}

Cell::~Cell() { }

void Cell::setLiving() {
   isAlive = true;
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
   } else if ((isAlive)&&(Live<= 3)&&(Live >= 2)){
        isAlive = true;
   } else if ((!isAlive)&&(Live == 3)){
        isAlive = true; 
   } else {
      isAlive = false;
   }
   Live = 0;
}
/*
void Cell::celllive(){
   if (isAlive) {
      cout << "live" << endl;
   }
   else {
      cout << "dead" << endl;
   }
}
*/
ostream &operator<<(ostream &out, const Cell &c) {
     if (c.isAlive) {
         out << "X";
     } else {
         out << "_";
     }
     return out;
}




