#ifndef _LIST_H_
#define _LIST_H_

class List {
  class Node;
  Node *theList = nullptr;

 public:
  class Iterator {
    Node *p;
    explicit Iterator(Node *p);
   public:
    int &operator*() const;
    Iterator &operator++();
    bool operator==(const Iterator &other) const;
    bool operator!=(const Iterator &other) const;
    friend class List;
  };

  Iterator begin();
  Iterator end();

  void addToFront(int n);
  int ith(int i);
  ~List();
};

#endif
