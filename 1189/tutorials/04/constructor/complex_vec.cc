#include <iostream>
using namespace std;

struct Complex{
	const int real;
	const int i;

	Complex(const int real, const int i) : real{real}, i{i} {}
	// No default constructor
	// Complex(bool empty = true) : real{empty ? 0 : 1}, i{empty ? 0 : 1} {}
	Complex(const Complex &c) : real{c.real}, i{c.i} {}

	const int getReal() {return real;}
	const int getImaginary() {return i;}
};

ostream &operator <<(ostream &out, Complex c){
	cout << c.getReal() << "+" << c.getImaginary() << "i";
	return out;
}

struct ComplexVector{
	Complex c1;
	Complex c2;

	ComplexVector(Complex &c1, Complex &c2) : c1{c1}, c2{c2} {}
};

ostream &operator <<(ostream &out, ComplexVector &cv){
	out << "(" << cv.c1 << ", " << cv.c2 << ")";
	return out;
}


int main(){
    Complex c1 {1, 3};
	Complex c2 {2, 5};
	ComplexVector cv {c1, c2};
    cout << cv << endl;
	return 0;
}
