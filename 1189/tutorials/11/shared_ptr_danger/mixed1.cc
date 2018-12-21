#include <iostream>
#include <memory>
using namespace std;

void f(int *p) {
    // Here, f creates a shared_ptr to p,
    // and it goes out of scope at the end of f
    shared_ptr<int> s{p};
}

int main() {
    int *p = new int{2};

    f(p);
    // Thus the heap memory pointed to by p is FREED at this point!

    cout << *p << endl; // What does this print out?
    // delete p; // Double free?
}
