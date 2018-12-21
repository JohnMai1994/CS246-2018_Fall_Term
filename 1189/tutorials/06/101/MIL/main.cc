#include <iostream>

using namespace std;

struct Foo{
	Foo(){
		cout << "Foo default ctor" << endl;
	}
	Foo(const Foo& f){
		cout << "Foo copy ctor" << endl;
	}

	Foo& operator=(const Foo& f){
		cout << "Foo assignment operator" << endl;
	}
};

struct Bar{
	Foo foo;
	Bar(const Foo& f){
		foo = f;
	}
	Bar(const Foo& f, int n): foo(f){
	}
};

int main(){
	Foo f;
	cout << " calling Bar ctor" << endl;
	Bar b(f);
	cout << " calling Bar ctor with int" << endl;
	Bar b1(f, 10);
}
