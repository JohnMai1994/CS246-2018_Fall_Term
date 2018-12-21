#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "point.h"
#include <iostream>

class Rectangle {

    /* Add your private variables and functions HERE */    

public:
	enum class Colour { Red, Green, Blue, Orange, Yellow, Black, White };

	Rectangle( Point upperLeft, int height, int width, Colour colour );
	void translate( int x = 0, int y = 0 );
	void scale( float heightFactor = 1.0, float widthFactor = 1.0 );
	void change( Colour newColour );
	Colour colour() const;
	Point point() const;
	int width() const;
	int height() const;
};

std::istream & operator>>( std::istream & in, Rectangle & rectangle );
std::ostream & operator<<( std::ostream & out, const Rectangle & rectangle );

#endif
