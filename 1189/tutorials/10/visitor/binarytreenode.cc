#include "binarytreenode.h"
#include "treenode.h"
#include "treevisitor.h"

BinaryTreeNode::BinaryTreeNode(int data, TreeNode *left, TreeNode *right)
        : TreeNode{data}, left{left}, right{right} {}

TreeNode *BinaryTreeNode::getLeft() { return left; }

TreeNode *BinaryTreeNode::getRight() { return right; }

void BinaryTreeNode::accept(TreeVisitor &v) { v.visit(*this); }

BinaryTreeNode::~BinaryTreeNode() {
    delete left;
    delete right;
}
