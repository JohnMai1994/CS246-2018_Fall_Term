#include "rectangle.h"
#include <iostream>
#include <string>
using namespace std;


Rectangle::Rectangle( Point upperLeft, int height, int width, Colour colour ): 
         point_name(upperLeft), height_name(height), width_name(width), colour_name(colour) {}

void Rectangle::translate( int x, int y  ){
     point_name = point_name + Point(x,y);
}


void Rectangle::scale( float heightFactor, float widthFactor ){
     height_name = height_name * heightFactor;
     width_name = width_name * widthFactor;
}

void Rectangle::change( Colour newColour ){
     colour_name = newColour;
}

Rectangle::Colour Rectangle::colour() const{
     return colour_name;
}

Point Rectangle::point() const{
     return point_name;
}


int Rectangle::width() const{
    return width_name;
}


int Rectangle::height() const{
    return height_name;
}



std::istream & operator>>( std::istream & in, Rectangle & rectangle ){
     char c;
     int x;
     int y;
     int height;
     int width;
     in >> c >> x >> y >> height >> width; 

     Point upperLeft = Point(x,y);                // translate x y into point
     
     Rectangle::Colour colour;
     if (c == 'r') {                              // translate character r into colour
       colour = Rectangle::Colour::Red;
     } else if (c == 'g') {
       colour = Rectangle::Colour::Green;
     } else if (c == 'b') {
       colour = Rectangle::Colour::Blue;
     } else if (c == 'o') {
       colour = Rectangle::Colour::Orange;
     } else if (c == 'y') {
       colour = Rectangle::Colour::Yellow;
     } else if (c == 'a') {
       colour = Rectangle::Colour::Black;
     } else if (c == 'w') {
       colour = Rectangle::Colour::White;
     } 
     rectangle = Rectangle(upperLeft, height, width, colour);
     return in;
}

std::ostream & operator<<( std::ostream & out, const Rectangle & rectangle ){
     out << "[" ;
     if (rectangle.colour() == Rectangle::Colour::Red) {
        out << "Red";
     } else if (rectangle.colour() == Rectangle::Colour::Green) {
        out << "Green";
     } else if (rectangle.colour() == Rectangle::Colour::Blue) {
        out << "Blue";
     } else if (rectangle.colour() == Rectangle::Colour::Orange) {
        out << "Orange";
     } else if (rectangle.colour() == Rectangle::Colour::Yellow) {
        out << "Yellow";
     } else if (rectangle.colour() == Rectangle::Colour::Black) {
        out << "Black";
     } else if (rectangle.colour() == Rectangle::Colour::White) {
        out << "White";
     } 

     out << " " << rectangle.point() << " " ;
     out << rectangle.height() << "x" << rectangle.width() << "]";
     return out;
}

