#include "cell.hpp"
//#include "window.h"

using namespace std;

Cell::Cell(): isAlive(false), blind(false), color(" "), window(nullptr), x(0), y(0) {}

Cell::~Cell() { }

void Cell::TurnOn(string new_color){
    isAlive = true;
    color = new_color;
}

void Cell::TurnOff(string new_color){
    isAlive = false;
    color = new_color;
}

void Cell::TurnBlind(){
    blind = true;
}

void Cell::NotBlind(){
    blind = false;
}


bool Cell::IsAlive(){
    return isAlive;
}

ostream &operator<<(ostream &out, const Cell &c) {
    if (!(c.blind)){
    out << c.color;
    }
    else {
        out << "?";
    }
    return out;
}


string Cell::GetColor (){
    return color;
}





void Cell::draw(int row, int col, Xwindow *board){
   if (color == "I") {
     board->fillRectangle(row * 25, col *25, 25, 25, 2);
   } else if (color == "J"){
     board->fillRectangle(row * 25, col *25, 25, 25, 3);
   } else if (color == "L"){
     board->fillRectangle(row * 25, col *25, 25, 25, 4);
   } else if (color == "Z"){
     board->fillRectangle(row * 25, col *25, 25, 25, 5);
   } else if (color == "S"){
     board->fillRectangle(row * 25, col *25, 25, 25, 9);
   } else if (color == "O"){
     board->fillRectangle(row * 25, col *25, 25, 25, 15);
   } else if (color == "T"){
     board->fillRectangle(row * 25, col *25, 25, 25, 8);
   } else if (color == "*"){
     board->fillRectangle(row * 25, col *25, 25, 25, 14);
   } else if (color == " ") {
     board->fillRectangle(row * 25, col *25, 25, 25, 7);
   } else if (color == "C") {
     board->fillRectangle(row * 25, col *25, 25, 25, 10);
   } else if (color == "X") {
     board->fillRectangle(row * 25, col *25, 25, 25, 11);
   }
   
    if (blind) {
        board->fillRectangle(row * 25, col *25, 25, 25, 6);
    }
}







