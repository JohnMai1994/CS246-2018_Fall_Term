#include <iostream>
using namespace std;

// A function foo
void foo(int x = 75){
	cout << x << endl;
}

// Another function foo2
void foo2(char c = 'A', int n = 32){
	char update = c + n;
	cout << update << endl;
}

int main(){
	// Which ones are using the default parameters?
	foo();
	foo(10);
	foo2();
	foo2('D');
}
