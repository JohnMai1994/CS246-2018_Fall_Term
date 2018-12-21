#include <iostream>
#include "node.h"
using namespace std;

Node::Node(int data, Node *next): data{data}, next{next} {}

Node::Node(const Node &n):
  data{n.data},
  next{n.next ? new Node{*n.next} : nullptr} {}

Node::~Node() {
  delete next;
}

void Node::swap(Node &other) {
  int tmpdata = data;
  data = other.data;
  other.data = tmpdata;

  Node *tmpnext = next;
  next = other.next;
  other.next = tmpnext;
}

Node &Node::operator=(const Node &other) {
  Node tmp = other;
  swap(tmp);
  return *this;
}

ostream &operator<<(ostream &out, const Node &n) {
  out << n.data;
  if (n.next) {
    out << "," << *n.next;
  }
  return out;
}
