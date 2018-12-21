#include <iostream>
#include <memory>
using namespace std;

// Example of mixing raw pointers and shared pointers...
// Example of what NOT TO DO!

struct MyClass {
    int data;
    MyClass() { cout << "Myclass Ctor" << endl; }
    ~MyClass() { cout << "MyClass Dtor called" << endl; }
};

int main() {
    MyClass *x = new MyClass;
    x->data = 5;

    shared_ptr<MyClass> sp{x};

    // Defining new scope
    {
        cout << "Making a duplicate shared_ptr with raw pointer...bad!" << endl;

        // If we didn't mix raw pointers with shared pointers we
        // could only create sp2 with copy construction, which would
        // increment the reference count.
        // Because we mixed them, sp2 thinks it is the only shared_ptr
        // to x and frees it when it goes out of scope!
        shared_ptr<MyClass> sp2{x};

        // Solution: Call new only in the parameter of a smart_ptr ctor
        // e.g. shared_ptr<MyClass> sp(new MyClass);

        // Or even better - don't call new yourself at all!
        // e.g. auto sp = make_shared<MyClass>()

        cout << "x's data is: " << x->data << endl;
    }
    // Arguably worse than first example because now we have a double free
    // at the end of our program. Although some may say this is better
    // as it's more clear we have a problem and less likely to be a bug
    // that makes it to production!
    cout << "Now my memory accesible through sp is gone!" << endl;
    cout << sp->data << endl;
}
