#include "point.h"
#include <iostream>
#include <string>
using namespace std;

Point::Point( int x , int y ): X(x), Y(y) {}

int Point::x() const{
    return X;
}

int Point::y() const{
    return Y;
}

Point Point::operator+( const Point & other ){
   return Point(X + other.X, Y + other.Y);
}

std::ostream & operator<<( std::ostream & out, const Point & point ){
     out << "(" << point.x() << "," << point.y() << ")"; 
     return out;
}
