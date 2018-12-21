#include <iostream>
#include "binarytreenode.h"
#include "nodecounter.h"
#include "prettyprinter.h"
#include "treenode.h"
#include "treevisitor.h"
#include "unarytreenode.h"
using namespace std;
int main() {
    // Modify these lines of code to create your own tree!
    TreeNode *t0 = new UnaryTreeNode{0, nullptr};
    TreeNode *t1 = new BinaryTreeNode{2, nullptr, nullptr};
    TreeNode *t2 = new UnaryTreeNode{
            1, new BinaryTreeNode{
                       2, new UnaryTreeNode{3, new UnaryTreeNode{4, nullptr}},
                       new BinaryTreeNode{5, new UnaryTreeNode{6, nullptr},
                                          new UnaryTreeNode{7, nullptr}}}};

    PrettyPrinter pp{cout};
    NodeCounter nc;

    t0->accept(pp);
	t0->accept(nc);
    cout << "t0 has " << nc.getNodeCount() << " nodes." << endl;
	nc.reset();


    t1->accept(pp);
	t1->accept(nc);
    cout << "t1 has " << nc.getNodeCount() << " nodes." << endl;
	nc.reset();

    t2->accept(pp);
	t2->accept(nc);
    cout << "t2 has " << nc.getNodeCount() << " nodes." << endl;
	nc.reset();
}
