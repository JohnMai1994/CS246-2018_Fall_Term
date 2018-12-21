#include <iostream>
#include <string>

using namespace std;

void inc(int *n) { ++*n;}

int main() {
    int x = 5;
    inc(&x);
    cout << x << endl;   // print 6 because it is a pointer
}
