#ifndef _LIST_H_
#define _LIST_H_
#include "abstractiterator.h"

template <typename T> class List {
  struct Node {
    T data;
    Node *next;

    Node (T data, Node *next): data{data}, next{next} {}
    ~Node() { delete next; }
  };
  Node *theList = nullptr;

 public:
  class Iterator: public AbstractIterator<T> {
    Node *p;
    explicit Iterator(Node *p): p{p} {}
   public:
    T &operator*() const override { return p->data; }
    Iterator &operator++() override {
      p = p -> next;
      return *this;
    }
    bool operator==(const AbstractIterator<T> &other) const override {
      const List::Iterator *that = dynamic_cast<const List::Iterator*>(&other);
      return that && p == that->p;
    }
    friend class List;
  };

  Iterator begin() { return Iterator(theList); }
  Iterator end() {return Iterator(nullptr); }

  void addToFront(T n) { theList = new Node(n, theList); }
  T ith(int i) {
    Node *cur = theList;
    for (int j = 0; j < i && cur; ++j, cur = cur -> next);
    return cur->data;
  }
  ~List() { delete theList; }
};

#endif
