#include <iostream>
using namespace std;

struct Complex{
	const int real;
	const int i;

    // Basic constructor (given by compiler if no constructor is defined) 
	Complex(const int real, const int i) : real{real}, i{i} {}

	// default constructor
	Complex(bool empty = true) : real{empty ? 0 : 1}, i{empty ? 0 : 1} {}

	// copy constructor
	Complex(const Complex &c) : real{c.real}, i{c.i} {}

	const int getReal() {return real;}
	const int getImaginary() {return i;}
};

ostream &operator <<(ostream &out, Complex c){
	cout << c.getReal() << "+" << c.getImaginary() << "i";
	return out;
}

int main(){
    Complex c1 {1, 3};
	Complex c2;
	Complex c3 {c1};
	cout << c1 << " " << c2 << " " << c3 << endl;
	return 0;
}
