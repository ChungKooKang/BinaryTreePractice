#include <iostream>

#include "BinaryTree.h"
int main()
{
	myTree::BinaryTree myTree;

	auto pRoot = myTree.GetRoot();
	pRoot->mData = 1;

	auto pNode = myTree.InsertLeft(pRoot, 2);
}

