#include <string>
#include <iostream>
using namespace std;
int neg(int n) {return -n;};
int neg(bool b) {return !b;};

int main(){
    int a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    int output = a+b+c;
    cout << "-(a+b+c) = " << neg(output) << endl;
    bool d = true;
    cout << neg(d) << endl;

}
