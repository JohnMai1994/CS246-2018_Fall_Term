#ifndef TREENODE_H
#define TREENODE_H
class TreeVisitor;
class TreeNode {
    int data;

public:
    TreeNode(int data);
    int getData();
    virtual void accept(TreeVisitor &v) = 0;
    virtual ~TreeNode();
};
#endif
