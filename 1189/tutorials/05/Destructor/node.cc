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
        if (begin < end){
            next = new Node{++begin, end};
            next->prev = this;
        }
    }

    // Destructor
    ~Node() { delete next; }
};

// Output operator
ostream &operator<<(ostream &out, const Node &n) {
    out << n.value;
    if (n.next) out << " <-> " << *(n.next);
    return out;
}

int main() {
    Node *n1 = new Node{1, 5};
    Node n2 {3, 6};
    cout << *n1 << endl;
    cout << n2 << endl;
    delete n1;
}

