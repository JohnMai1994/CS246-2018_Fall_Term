#include <iostream>
#include "Node.h"
using namespace std;

Node::Node(int data, Node *next): data {data}, next {next} {}

Node::Node(const Node &n): data {n.data},
                           next {n.next ? new Node(*n.next) : nullptr} {}

ostream &operator<<(ostream &out, const Node &n) {
  out << n.data;
  if (n.next) {
    out << ',';
    out << *n.next;
  }
  return out;
}

