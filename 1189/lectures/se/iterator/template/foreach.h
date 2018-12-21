#ifndef _FOREACH_H_
#define _FOREACH_H_
#include "abstractiterator.h"

template <typename T, typename Fn>
  void for_each(AbstractIterator<T> &&first, AbstractIterator<T> &&last, Fn f) {
  while (first != last) {
    f(*first);
    ++first;
  }
}

#endif
