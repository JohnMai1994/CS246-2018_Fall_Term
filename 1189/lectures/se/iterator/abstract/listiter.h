#ifndef _LIST_H_
#define _LIST_H_
#include "abstractiterator.h"

class List {
  class Node;
  Node *theList = nullptr;

 public:
  class Iterator: public AbstractIterator {
    Node *p;
    explicit Iterator(Node *p);
   public:
    int &operator*() const override;
    Iterator &operator++() override;
    bool operator==(const AbstractIterator &other) const override;
    friend class List;
  };

  Iterator begin();
  Iterator end();

  void addToFront(int n);
  int ith(int i);
  ~List();
};

#endif
