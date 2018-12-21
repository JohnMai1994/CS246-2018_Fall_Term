#ifndef NODECOUNTER_H
#define NODECOUNTER_H
#include "treevisitor.h"
class UnaryTreeNode;
class BinaryTreeNode;

struct NodeCounter : public TreeVisitor {
  private:
	int nodeCount = 0;	

  public:
	int getNodeCount();

    void visit(UnaryTreeNode &t) override;
    void visit(BinaryTreeNode &t) override;

	void reset();
};

#endif
