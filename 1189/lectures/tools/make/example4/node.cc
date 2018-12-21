#include "list.h"
#include "node.h"

List::Node::Node (int data, Node *next): data{data}, next{next} {}
List::Node::~Node() { delete next; }

