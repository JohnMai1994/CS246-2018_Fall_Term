#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int data, Node *next): data {data}, next {next} {}

  Node(const Node &n): data {n.data}, next {n.next} {}
};

ostream &operator<<(ostream &out, const Node &n) {
  out << n.data;
  if (n.next) {
    out << ",";
    out << *(n.next);
  }
  return out;
}

int main() {
  Node *n = new Node{1, new Node{2, new Node{3, nullptr}}};

  Node m {*n};
  m.data = 5;

  Node *p = new Node {*n};
  p->data = 6;

  cout << "n: " << *n << endl;
  cout << "m: " << m << endl;
  cout << "p: " << *p << endl;
  cout << endl;

  n->next->next->data = 7;

  cout << "n: " << *n << endl;
  cout << "m: " << m << endl;
  cout << "p: " << *p << endl;
}
