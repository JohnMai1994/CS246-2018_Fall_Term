#include "unarytreenode.h"
#include "treenode.h"
#include "treevisitor.h"

UnaryTreeNode::UnaryTreeNode(int data, TreeNode *child)
        : TreeNode{data}, child{child} {}

TreeNode *UnaryTreeNode::getChild() { return child; }

void UnaryTreeNode::accept(TreeVisitor &v) { v.visit(*this); }

UnaryTreeNode::~UnaryTreeNode() { delete child; }
