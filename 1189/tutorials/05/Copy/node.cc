#include <iostream>
#include <utility>
using namespace std;

struct Node {
    int value;
    Node *next = nullptr;
    Node *prev = nullptr;

    // Constructors
    explicit Node(int value) : value{value} {}
    Node(int begin, int end) : value{begin} {
        if (begin < end) {
            next = new Node {++begin, end};
            next->prev = this;
        }
    }

    // Destructor
    ~Node() { delete next; }

    // Copy Constructor
    Node(const Node &other) : value{other.value}, 
        next{other.next ? new Node{*(other.next)} : nullptr} {
        if (next) next->prev = this;
        cout << "Copy ctor for value = " << value << endl;
    } 

    // Copy Assignment Operator
    Node &operator=(const Node &other) {
        Node copy = other;
        swap(value, copy.value);
        swap(next, copy.next);
        swap(prev, copy.prev);
        cout << "copy assignment operator" << endl;
        return *this;
    }
};

// Output operator
ostream &operator<<(ostream &out, const Node &n) {
    out << n.value;
    if (n.next) out << " <-> " << *(n.next);
    return out;
}

int main() {
    Node *n1 = new Node{7, 10};
    
    //Copy constructor invoked
    Node n2 = *n1;
    delete n1;
    cout << n2 << endl;
    
    //Copy assignment invoked
    Node *n3 = new Node{8};
    *n3 = n2;
    cout << *n3 << endl;
    delete n3;
}

