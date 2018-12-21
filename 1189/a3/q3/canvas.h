#ifndef _CANVAS_H
#define _CANVAS_H
#include "rectangle.h"

class Canvas {

    /* Add you private variables and functions HERE */

public:
	Canvas();
	Canvas( const Canvas & other );
	Canvas( Canvas && other );
	~Canvas();
	Canvas & operator=( const Canvas & other );
	Canvas & operator=( Canvas && other );
	void add( const Rectangle & rectangle ); // add rectangle after all others
	int numRectangles() const; // returns number of rectangles in the canvas
	int width() const; // returns the width of the canvas
	int height() const; // returns the height of the canvas
	Rectangle get( int rectangleId ) const;
	void translate( int rectangleId, int x = 0, int y = 0 );
	void scale( int rectangleId, float heightFactor = 1.0, float widthFactor = 1.0 );
	void change( int rectangleId, Rectangle::Colour newColour );
	void remove( int rectangleId );
};

std::ostream & operator<<( std::ostream & out, const Canvas & canvas );

#endif
