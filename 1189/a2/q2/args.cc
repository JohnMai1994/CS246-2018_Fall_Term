#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << "This run of program " << argv[0] << " had " << argc - 1 
	<< " arguments:" << endl;
    for (int i = 1; i < argc; ++i) {
	string theArg = argv[i];
	cout << "    " << i << ": " << theArg << endl;
    }
}
