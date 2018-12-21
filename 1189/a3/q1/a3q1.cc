#include "plan.h"

int main() {
	Date date{2018, 9, 26}; 
	Call call{date, 500, 10};
	Plan plan;
    bool done = false;

	while ( ! done ) {
		char command;
		std::cin >> command;
		if ( std::cin.eof() ) break;

		switch( command ) {
			case '+':
				std::cin >> call;
				plan.add( call );
				break;
			case 'p':
				std::cout << plan;
				break;
			case 'b':
				plan.calculateBill();
				break;
			case 'q':
				done = true;
				break;
			default:
				std::cerr << "Unrecognized command: '" << command << "'" << std::endl;
		} // switch
	} // while
	return 0;
} // main
