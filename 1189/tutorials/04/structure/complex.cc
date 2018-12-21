#include <iostream>
using namespace std;

struct Complex{
	int real;
	int i;

	int getReal();
	int getImaginary();
	Complex &operator +(int num);
};

int Complex::getReal(){
	return real;
}

int Complex::getImaginary(){
	return i;
}

Complex &Complex::operator +(int num){
	real += num;
    return *this;
}

ostream &operator <<(ostream &out, Complex c){
	out << c.getReal() << "+" << c.getImaginary() << "i";
	return out;
}

int main(){
    Complex c {1, 3};
    cout << "The original value is " << c << endl;
	cout << c;
	c + 1 + 1 + 1;
    cout << " + 3 is " << c << endl;
	return 0;
}
