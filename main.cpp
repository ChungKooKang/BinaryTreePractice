#include <iostream>

#include "BinaryTree.h"
#include "quadtree.h"

int main()
{
	QuadTree qt1(Point(0,0), Point(8, 8));

	std::unique_ptr<Node> a = std::make_unique<Node>(Point(1, 1), 1);
	std::unique_ptr<Node> b = std::make_unique<Node>(Point(2, 2), 2);
	std::unique_ptr<Node> c = std::make_unique<Node>(Point(3, 3), 3);
	std::unique_ptr<Node> d = std::make_unique<Node>(Point(4, 4), 4);

}