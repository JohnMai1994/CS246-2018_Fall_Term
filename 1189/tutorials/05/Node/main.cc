#include <iostream>
#include "node.h"

using std::cout;
using std::endl;

void example0();
void example1();
void example2();
void example3();
void example4();
void example5();
void examplex();

int main() {
//    example0(); // Example: Destructor
//    example1(); // Example: Copy ctor
//    example2(); // Example: Copy operator=
//    example3(); // Example: Self-assignment
//    example4(); // Example: Move ctor
//    example5(); // Example: Move assignment
example4();
}

void example0() {
    Node *n1 = new Node{1, 5};
    cout << *n1 << endl;
    delete n1;
}

void example1() {
    Node *n1 = new Node{7};
    n1->add(3);
    n1->add(5);
    n1->add(10);

    // create n2 -> copy n1
    Node n2 = *n1;

    delete n1;
    cout << n2 << endl;
}

void example2() {
    Node *n1 = new Node{7};
    n1->add(3);
    n1->add(5);
    n1->add(10);
    Node *n2 = new Node{8};
    n2->add(12);

    // assign n2 to be equal to n1
    *n2 = *n1;

    delete n1;
    cout << *n2 << endl;
    delete n2;
}

void example3() {
    Node *n1 = new Node{0, 7};

    // assign n1 to itself
    *n1 = *n1;

    cout << *n1 << endl;
    delete n1;
}

Node func(){
    Node retVal{7};
    return retVal;
}
void examplex(){
Node n3 = func();
cout << n3 << endl;
}

void example4(){
    Node n1{3};
    Node n2 = plus(n1,2);
    cout << "n2: " << n2 <<endl;
}
void example5(){
    Node n1 {3};
    Node n2 {1};
    n2 = plus(n1,2);
    cout <<"n1:  "<< n1 << endl;
    cout <<"n2:  "<< n2 << endl;
}
