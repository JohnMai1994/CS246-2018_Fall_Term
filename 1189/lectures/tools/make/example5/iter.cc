#include "list.h"
#include "node.h"

List::Iterator::Iterator(Node *p): p{p} {}
int &List::Iterator::operator*() const { return p->data; }
List::Iterator &List::Iterator::operator++() {
  p = p -> next;
  return *this;
}
bool List::Iterator::operator==(const Iterator &other) const {
  return p == other.p;
}
bool List::Iterator::operator!=(const Iterator &other) const {
  return !(*this == other);
}

