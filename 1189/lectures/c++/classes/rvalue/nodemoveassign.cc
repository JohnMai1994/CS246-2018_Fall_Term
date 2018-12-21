#include <iostream>
#include <utility>
using namespace std;

struct Node {
  int data;
  Node *next;
  void swap(Node &other) {
    using std::swap;
    swap(data, other.data);
    swap(next, other.next);
  }
  Node (int data, Node *next): data{data}, next{next} {
    cout << "Basic ctor" << endl;
  }
  Node (const Node &other) : data{other.data},
   next{other.next ? new Node {*other.next} : nullptr} {
    cout << "Copy ctor" << endl;
  }
  Node &operator=(const Node &other) {
    cout << "Copy assignment" << endl;
    Node n {other};
    swap(n);
    return *this;
  }
  Node &operator=(Node &&other) {
    cout << "Move assignment" << endl;
    swap(other);
    return *this;
  }
  Node (Node &&other) : data{other.data}, next{other.next} {
    other.next = nullptr;
    cout << "Move ctor" << endl;
  }
  ~Node() { delete next; }
};

Node plusOne(Node n) {
  for (Node *p {&n}; p ; p = p->next) {
    ++p->data;
  }
  return n;
}

ostream &operator<<(ostream &out, const Node &n) {
  out << n.data;
  if (n.next) out << ' ' << *n.next;
  return out;
}

int main() {
  Node n {1, new Node {2, nullptr}};

  Node n2 {plusOne(n)};

  n2 = plusOne(n2);

  cout << n << endl << n2 << endl;
}
