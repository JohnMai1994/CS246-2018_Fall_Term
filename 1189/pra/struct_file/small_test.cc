#include <iostream>

using namespace std;

int main() {
    cout << "beginning, y is equal to 10" << endl;
    int y = 10;
    int &z = y;
    cout << "z's value is "<< z << endl;
    cout << "change y's value" << endl;
    cout << "now y is equal to 12" << endl;
    y = 12;
    cout << "z's value now is "<<z << endl;
  
}

