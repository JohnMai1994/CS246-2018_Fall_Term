#include <iostream>
#include "binarynum.h"
using namespace std;

// TEST HARNESS
// DO NOT MODIFY THIS FILE IN ANY WAY
// Be sure to understand what the following does
// in order to create appropriate test cases.
int main() {
    const int arr_size = 4;
    BinaryNum a[arr_size];
    for (int i = 0; i < arr_size; ++i) {
	a[i].contents = nullptr;
    }

    bool done = false;
    while (!done) {
        char c;
        char which;
        cin >> c; // reads r, +, d, p, s or q
        if (cin.eof()) break;
        switch(c) {
            case 'r':
                cin >> which; // reads a b c or d
                delete[] a[which-'a'].contents;
                a[which-'a'].contents = nullptr;
                a[which-'a'] = readBinaryNum();
                break;
            case '+':
                cin >> which; // reads a b c or d
                binaryConcat(a[which-'a']);
                break;
            case 'p':
                cin >> which; // reads a b c or d
                char sep;
                cin >> sep; // reads one char for sep char.
                printBinaryNum(cout, a[which-'a'],sep);
                cout << endl;
                break;
            case 'd':
                cin >> which; // reads a b c or d
                cout << binaryToDecimal(a[which-'a']) << endl;
                break;
            case 's':
                cin >> which; // reads a b c or d
                int x;
                cin >> x; // reads how much to shift by.
                a[which-'a'] << x;
                break;
            case 'q':
                done = true;
                break;
        }
    }
    for (int i = 0; i < arr_size; ++i) {
	delete[] a[i].contents;
    }
}
