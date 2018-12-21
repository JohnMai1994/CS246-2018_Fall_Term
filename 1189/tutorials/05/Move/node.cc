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

    // Move Constructor
    Node(Node &&other) : value{other.value}, next{other.next}, prev{other.prev} {
        other.next = nullptr;
        cout << "Move ctor for value = " << value << endl;
    }

    // Move Assignment Operator
    Node &operator=(Node &&other) {
        swap(value, other.value);
        swap(next, other.next);
        swap(prev, other.prev);
        cout << "Move assignment operator" << endl;
        return *this;
    }
};

// Output operator
ostream &operator<<(ostream &out, const Node &n) {
    out << n.value;
    if (n.next) out << " <-> " << *(n.next);
    return out;
}

Node makeANode(int begin, int end){
    Node n {begin, end};
    return n;
}

int main() {
    Node n1 {move(makeANode(1, 8))}; // Move Construction
            // To see the move ctor message, use -fno-elide-constructors flag
    Node n2 {1};
    n2 = makeANode(20, 25); // Move Assignment
    cout << "n1: " << n1 << endl;
    cout << "n2: " << n2 << endl;
}
