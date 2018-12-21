#include <iostream>
using namespace std;

/* HOW TO ATTEMPT TO COMPILE THIS PROGRAM:

   You can attempt a compile to see whether an option for a foo overload will work.
   However, you must follow the below instructions to include the definition of an
   overloaded version.

   Below each option, there is a line like: #ifdef X, where X is A,B,C,or D.
   When compiling, you should use the following command:
   (assuming the aliases are set)

   g++14 -DX overload.cc

   With the X replaced with A,B,C,or D as appropriate.
*/


// Our original foo function.
bool foo(int x, char c) {
	return true;
}

// Option 1
#ifdef A
bool foo() {
	return false;
}
#endif

// Option 2
#ifdef B
char foo(char x, int c){
	return 'c';
}
#endif

// Option 3
#ifdef C
bool foo(int c){
	return true;
}
#endif

// Option 4
#ifdef D
int foo(int x, char c, int y = 10){
	return 246;
}
#endif

// Attempt to use foo.
int main() {
    int my_int = 2;
    char my_char = 'c';
	cout << boolalpha << foo(my_int, my_char) << endl;
}
