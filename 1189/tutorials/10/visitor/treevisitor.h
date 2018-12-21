#ifndef TREEVISITOR_H
#define TREEVISITOR_H
class UnaryTreeNode;
class BinaryTreeNode;

struct TreeVisitor {
    virtual void visit(UnaryTreeNode &t) = 0;
    virtual void visit(BinaryTreeNode &t) = 0;
};

#endif
