#include "canvas.h"
using namespace std;

const int NUM_CANVASES = 5;

bool validateCanvasId( int cid ) {
	if ( cid < 0 || cid >= NUM_CANVASES ) {
		cerr << "Invalid canvas id " << cid << endl;
		return false;
	} // if
	return true;
} // validateCanvasId

bool validateRectangleId( int rid, int numRectangles ) {
	if ( rid < 0 || rid >= numRectangles ) {
		cerr << "Invalid rectangle id " << rid << endl;
		return false;		
	} // if
	return true;
} // validateRectangleId

void errOption( char option ) {
	cerr << "Unrecognized option: '" << option << "'" << endl;
}

Rectangle::Colour translateColour( char c ) {
	switch( c ) {
		case 'r' : return Rectangle::Colour::Red;
		case 'g' : return Rectangle::Colour::Green;
		case 'b' : return Rectangle::Colour::Blue;
		case 'y' : return Rectangle::Colour::Yellow;
		case 'o' : return Rectangle::Colour::Orange;
		case 'a' : return Rectangle::Colour::Black;
		case 'w' : return Rectangle::Colour::White;
	}
	return Rectangle::Colour::Red;
} // translate

int main() {

	Canvas canvases[NUM_CANVASES];

	while (true) {
		char command, option, c; 
		int cid1, cid2, rid; // canvas id #1, canvas id #2, rectangle id #
		int x, y; // translate values
		float s1, s2; // scale factors
		Rectangle rectangle{ Point{}, 0, 0, Rectangle::Colour::Red };

		cin >> command;
		if ( cin.eof() ) break;

		switch( command ) {
			case 'a':
				// add a rectangle to the specified canvas
				cin >> cid1 >> rectangle;
				if ( validateCanvasId( cid1 ) ) {
					canvases[ cid1 ].add( rectangle );
				}
				break;
			case 'r':
				// remove the specified rectangle from the specified canvas
				cin >> cid1 >> rid;
				if ( validateCanvasId( cid1 ) && 
					validateRectangleId( rid, canvases[ cid1 ].numRectangles() ) ) 
				{
					canvases[ cid1 ].remove( rid );
				}
				break;
			case 'p':
				cin >> option >> cid1;
				if ( validateCanvasId( cid1 ) ) {
					switch ( option ) {
						case 'c':
							// print the specified canvas' contents
							cout << canvases[ cid1 ];
							break;
						case 'r':
							// prints the specified rectangle from the specified canvas
							cin >> rid;
							if ( validateRectangleId( rid, canvases[ cid1 ].numRectangles() ) ) {
								cout << canvases[ cid1 ].get( rid ) << endl;
							}
							break;
						default:
							errOption( option );
					} // switch	
				} // if							
				break;
			case '=': // assign
				cin >> option >> cid1 >> cid2;
				if ( validateCanvasId( cid1 ) && validateCanvasId( cid2 ) ) {
					switch ( option ) {
						case 'c':
							// assignment of one canvas to another (uses copy operator=)
							canvases[ cid1 ] = canvases[ cid2 ];
							break;
						case 'm':
							// assignment of one canvas to another (uses move operator=)
							canvases[ cid1 ] = std::move( canvases[ cid2 ] );
							break;
						default:
							errOption( option );
					} // switch
				} // if				
				break;
			case 'c': // create a copy of the specified canvas in a temporary canvas
				cin >> option >> cid1;
				if ( validateCanvasId( cid1 ) ) {
					switch ( option ) {
						case 'c':
						{
							// uses copy ctor
							Canvas tmpCanvas{ canvases[cid1] };
							tmpCanvas.add( Rectangle{ Point{20,20}, 5, 15, Rectangle::Colour::Yellow } );
							tmpCanvas.add( Rectangle{ Point{0,20}, 10,30, Rectangle::Colour::Blue } );
							tmpCanvas.remove( 0 );
							cout << "temporary canvas\n" << tmpCanvas;
							break;
						}
						case 'm':
						{
							// uses move ctor
							Canvas tmpCanvas{ std::move( canvases[cid1] ) };
							tmpCanvas.add( Rectangle{ Point{20,20}, 5, 15, Rectangle::Colour::Yellow } );
							tmpCanvas.add( Rectangle{ Point{0,20}, 10,30, Rectangle::Colour::Blue } );
							tmpCanvas.remove( 0 );
							cout << "temporary canvas\n" << tmpCanvas;
							break;
						}
						default:
							errOption( option );
					} // switch		
				} // if		
				break; 
			case 's': // set rectangle from the specified canvas
				cin >> option >> cid1 >> rid;
				if ( validateCanvasId( cid1 ) && 
					validateRectangleId( rid, canvases[ cid1 ].numRectangles() ) ) 
				{
					switch( option ) {
						case 'c': // colour
							cin >> c;
							canvases[ cid1 ].change( rid, translateColour(c) );
							break;
						case 't': // translate
							cin >> x >> y;
							canvases[ cid1 ].translate( rid, x, y );
							break;
						case 's': // scale
							cin >> s1 >> s2;
							canvases[ cid1 ].scale( rid, s1, s2 );
							break;
						default:
							errOption( option );
					} // switch
				} // if
				break;
			default:
				cerr << "Unrecognized command: '" << command << "'" << std::endl;
		} // switch
	} // while

	return 0;
}
