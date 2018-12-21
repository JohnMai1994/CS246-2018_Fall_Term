#ifndef _LIST_H_
#define _LIST_H_

class List {
  class Node;
  Node *theList = nullptr;

 public:
  void addToFront(int n);
  int ith(int i);
  ~List();
};

#endif
