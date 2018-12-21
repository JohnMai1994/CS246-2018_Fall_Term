#ifndef _ARRAYITER_H_
#define _ARRAYITER_H_
#include "abstractiterator.h"

template <typename T> class Array {
  int size = 0;
  T **contents = nullptr;
 public:
  const int maxItems = 100;
  Array(): contents{new T*[maxItems]} {}
  ~Array() {
    for (int i = 0; i < size; ++i) {
      delete contents[i];
    }
    delete [] contents;
  }
  void insert (T x) {
    if (size < maxItems) {
      contents[size++] = new T{x};
    }
  }

  class Iterator: public AbstractIterator<T> {
    T **p;
    explicit Iterator(T **p): p{p} {}
   public:
    T &operator*() const override { return **p; }
    Iterator &operator++() override {
      ++p;
      return *this;
    }
    bool operator==(const AbstractIterator<T> &other) const override {
      const Iterator *that = dynamic_cast<const Iterator*>(&other);
      return that && p == that->p;
    }
    friend class Array;
  };

  Iterator begin() { return Iterator{contents}; }
  Iterator end() { return Iterator{contents + size}; }
};

#endif
