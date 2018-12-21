#ifndef _ABSTRACTITERATOR_H_
#define _ABSTRACTITERATOR_H_

template <typename T> class AbstractIterator {
 public:
  virtual T &operator*() const = 0;
  virtual AbstractIterator &operator++() = 0;
  virtual bool operator==(const AbstractIterator &other) const = 0;
  bool operator!=(const AbstractIterator &other) const {
    return !(*this == other);
  }
  virtual ~AbstractIterator() {};
};

#endif
