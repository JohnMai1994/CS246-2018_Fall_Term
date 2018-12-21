#include "nodecounter.h"
#include "binarytreenode.h"
#include "unarytreenode.h"
void NodeCounter::visit(UnaryTreeNode &t) {
	nodeCount += 1;
    if ( t.getChild() ){
		t.getChild()->accept(*this);
	}
}
void NodeCounter::visit(BinaryTreeNode &t) {
	nodeCount += 1;
    if ( t.getRight() ){
		t.getRight()->accept(*this);
	}
    if ( t.getLeft() ){
		t.getLeft()->accept(*this);
	}
}

void NodeCounter::reset(){
	nodeCount = 0;
}

int NodeCounter::getNodeCount(){ return nodeCount; }
