#ifndef _ABSTRACTITERATOR_H_
#define _ABSTRACTITERATOR_H_

class AbstractIterator {
 public:
  virtual int &operator*() const = 0;
  virtual AbstractIterator &operator++() = 0;
  virtual bool operator==(const AbstractIterator &other) const = 0;
  bool operator!=(const AbstractIterator &other) const;
  virtual ~AbstractIterator();
};

#endif
