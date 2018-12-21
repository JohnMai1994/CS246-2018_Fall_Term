#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>

struct Node {
  int data;
  Node *next;
  explicit Node(int data, Node *next = nullptr);
  Node(const Node &n);

  ~Node();

  Node &operator=(const Node &other);

  void swap(Node &other);
};

std::ostream &operator<<(std::ostream &out, const Node &n);

#endif
