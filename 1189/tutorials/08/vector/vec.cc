#include <iostream>
#include <vector>
using namespace std;

class A {
    int x;
public:
    A(int x) : x{x} {}

    int get_x() const { return x; }
};

int main() {
    // Creating a new vector
    vector<A> array; // Default ctor initialize an empty vector

    // Placing items to the back of the vector
    cout << "Supply numbers to enter into the vector:" << endl;
    int x;
    while (cin >> x) {
        A a{x};
        array.emplace_back(a);
    }

    // The size of the vector is
    cout << "The size of the vector is " << array.size() << endl;

    // Iterating through the vector
    cout << "The vector is: [";
    for (vector<A>::iterator it = array.begin(); it != array.end(); ++it) {
        cout << it->get_x();
        if (it != array.end() - 1) cout << ",";
    }
    cout << "]" << endl;

    // Pop the last 3 elements
    cout << "The last three elements are removed from the vector" << endl;
    for (int i = 0; i < 3; ++i) array.pop_back();
    
    // Return the first and last element
    cout << "The first element is: " << array.front().get_x() << endl;
    cout << "The last element is: " << array.back().get_x() << endl; 
}
