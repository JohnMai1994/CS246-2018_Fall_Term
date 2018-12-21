#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node (int data, Node *next): data{data}, next{next} {
    cout << "Basic ctor" << endl;
  }
  Node (const Node &other) : data{other.data},
   next{other.next ? new Node {*other.next} : nullptr} {
    cout << "Copy ctor" << endl;
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

  cout << n << endl << n2 << endl;
}
