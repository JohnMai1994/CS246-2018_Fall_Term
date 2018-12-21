#ifndef _LIST_H_
#define _LIST_H_

template <typename T> class List {
  struct Node {
    T data;
    Node *next;

    Node (T data, Node *next): data{data}, next{next} {}
    ~Node() { delete next; }
  };

  Node *theList = nullptr;

 public:
  class Iterator {
    Node *p;
    explicit Iterator(Node *p): p{p} {}
   public:
    T &operator*() const { return p->data; }
    Iterator operator++() {
      p = p -> next;
      return *this;
    }
    bool operator==(const Iterator &other) const {
      return p == other.p;
    }
    bool operator!=(const Iterator &other) const {
      return !(*this == other);
    }
    friend class List<T>;
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
