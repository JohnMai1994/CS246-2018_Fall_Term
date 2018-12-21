#ifndef PRETTYPRINTER_H
#define PRETTYPRINTER_H
#include <iostream>
#include "treevisitor.h"
#include <string>

class TreeNode;
class UnaryTreeNode;
class BinaryTreeNode;

class PrettyPrinter : public TreeVisitor {
    std::ostream &out;
	std::string indent;

	void printNode(TreeNode* t);

public:
    PrettyPrinter(std::ostream &out);
    void visit(UnaryTreeNode &t) override;
    void visit(BinaryTreeNode &t) override;
};

#endif
