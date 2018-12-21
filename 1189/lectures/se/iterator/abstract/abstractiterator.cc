#include "abstractiterator.h"

bool AbstractIterator::operator!=(const AbstractIterator &other) const {
  return !(*this == other);
}

AbstractIterator::~AbstractIterator() {}
