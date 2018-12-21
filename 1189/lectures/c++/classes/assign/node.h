#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>

struct Node {
  int data;
  Node *next;
  explicit Node(int data, Node *next = nullptr): data{data}, next{next} {}

  Node(const Node &n):
    data{n.data},
    next{n.next ? new Node{*n.next} : nullptr} {}

  ~Node() {
    delete next;
  }

  Node &operator=(const Node &other) {
    if (this == &other) return *this;
    data = other.data;
    Node *tmp = next;
    next = other.next ? new Node(*other.next) : nullptr;
    delete tmp;
    return *this;
  }
};

std::ostream &operator<<(std::ostream &out, const Node &n);
#endif
