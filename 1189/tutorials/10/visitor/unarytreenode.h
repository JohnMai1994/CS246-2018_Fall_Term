#ifndef UNARYTREENODE_H
#define UNARYTREENODE_H
#include "treenode.h"
class TreeVisitor;
class UnaryTreeNode : public TreeNode {
    TreeNode *child;

public:
    UnaryTreeNode(int data, TreeNode *child = nullptr);
    TreeNode *getChild();
    void accept(TreeVisitor &v) override;
    virtual ~UnaryTreeNode();
};
#endif
