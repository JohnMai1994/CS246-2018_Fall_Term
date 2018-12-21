#include <iostream>
using namespace std;

struct EvenInteger{
	int num;

    EvenInteger operator +(EvenInteger i){
        EvenInteger new_i {i.num + num};
		return new_i;
	}    

    friend ostream &operator <<(ostream &out, EvenInteger &o);
    friend istream &operator >>(istream &in, EvenInteger &i);
};

ostream &operator <<(ostream &out, EvenInteger &o){
	out << o.num;
    return out;
}

istream &operator >>(istream &in, EvenInteger &i){
	int integer;
    if (in >> integer && integer % 2 == 0){
        i.num = integer;
	} else {
        cerr << "Can't read the even number" << endl;
	}
    return in;
}

int main(){
    EvenInteger even_int1, even_int2, even_int3;
    cin >> even_int1;
    cin >> even_int2;
    even_int3 = even_int1 + even_int2;
    cout << "Their sum is: " << even_int3 << endl;
	return 0;
}


