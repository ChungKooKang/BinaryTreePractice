#include <iostream>

#include "BinaryTree.h"

int main()
{
	myTree::BinaryTree myTree;

	auto pRoot = myTree.GetRoot();
	pRoot->mData = 1;

	auto pNode = myTree.InsertLeft(pRoot, 2);
	myTree.InsertLeft(pNode, 4);
	myTree.InsertRight(pNode, 5);

	pNode =	myTree.InsertRight(pRoot, 3);
	myTree.InsertLeft(pNode, 6);
	myTree.InsertRight(pNode, 7);
	

	std::cout << myTree.Sum(myTree.GetRoot()) << std::endl
		<< myTree.Search(myTree.GetRoot(), 10) << std::endl;
}