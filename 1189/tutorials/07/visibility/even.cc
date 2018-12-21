#include <iostream>
using namespace std;

class EvenInteger{

	int num = 0;

public:
    EvenInteger() : num{0} {}
    EvenInteger(int num) {
        if (num % 2 == 0) this->num = num;
        else {
            cerr << "Integer " << num << " rounded down to " << num - 1 << endl;
            this->num = num - 1;
        }
    }

    EvenInteger operator +(EvenInteger i){
        EvenInteger new_i {i.num + num};
		return new_i;
	}

    friend ostream &operator <<(ostream &out, const EvenInteger &even);
};

ostream &operator <<(ostream &out, const EvenInteger &even){
    out << even.num;
    return out;
}


int main(){
    EvenInteger even1, even2{4}, even3{7};
    cout << even1 << " " << even2 << " " << even3 << endl;
	return 0;
}


