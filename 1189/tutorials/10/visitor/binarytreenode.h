#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
#include "treenode.h"
class TreeVisitor;
class BinaryTreeNode : public TreeNode {
    TreeNode *left;
    TreeNode *right;

public:
    BinaryTreeNode(int data, TreeNode *left = nullptr,
                   TreeNode *right = nullptr);
    TreeNode *getLeft();
    TreeNode *getRight();
    void accept(TreeVisitor &v) override;
    virtual ~BinaryTreeNode();
};
#endif
