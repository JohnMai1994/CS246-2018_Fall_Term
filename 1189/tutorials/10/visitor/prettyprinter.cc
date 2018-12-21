#include "prettyprinter.h"
#include <iostream>
#include "binarytreenode.h"
#include "unarytreenode.h"
using namespace std;

/* Optional exercise: Change the implementation of PrettyPrinter
 * such that the child node prints with one more trailing space than it's
 * parent (the root node prints no trailing space).
 */

PrettyPrinter::PrettyPrinter(ostream &out) : out{out} {}

void PrettyPrinter::printNode(TreeNode* t){
    if (t){
        t->accept(*this);
	} else {
        out << indent << "empty" << endl;
	}
}

void PrettyPrinter::visit(UnaryTreeNode &t) {
    out << indent << "UnaryTreeNode: " << t.getData() << endl;
    out << indent << "child: {" << endl;
	indent += " ";
	printNode(t.getChild());
	indent = indent.substr(1);
    out << indent << "}" << endl;

}

void PrettyPrinter::visit(BinaryTreeNode &t) {
    out << indent << "BinaryTreeNode: " << t.getData() << endl;
    out << indent << "left: {" << endl;
	indent += " ";
    printNode(t.getLeft());
	indent = indent.substr(1);
    out << indent << "}" << endl << indent << "right: {" << endl;
	indent += " ";
	
    printNode(t.getRight()); 
	indent = indent.substr(1);
    out << indent << "}" << endl;
}
