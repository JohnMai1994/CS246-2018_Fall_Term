#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int data, Node *next): data(data), next(next) {}
};

int dotProduct(Node *n, Node *m) {
  if (!n) return 0;
  int current = n->data * m->data;
  return current + dotProduct(n->next, m->next);
}

int main () {
  Node *m = new Node(1, new Node(2, new Node(3, NULL)));
  Node *n = new Node(5, new Node(6, new Node(7, new Node(7, NULL))));

  cout << dotProduct(n, m) << endl;
}
