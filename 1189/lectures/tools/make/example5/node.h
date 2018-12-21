#ifndef _NODE_H_
#define _NODE_H_
#include "list.h"

struct List::Node {
  int data;
  Node *next;

  Node (int data, Node *next);
  ~Node();
};

#endif
