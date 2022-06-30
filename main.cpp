#include <iostream>

#include "BinaryTree.h"
#include "quadtree.h"

int main()
{
	QuadTree qt1(Point(0, 0), Point(8, 8));

	std::unique_ptr<Node> a = std::make_unique<Node>(Point(1, 1), 1);
	std::unique_ptr<Node> b = std::make_unique<Node>(Point(2, 2), 2);
	std::unique_ptr<Node> c = std::make_unique<Node>(Point(3, 3), 3);
	std::unique_ptr<Node> d = std::make_unique<Node>(Point(4, 4), 4);

	qt1.Insert(a.get());
	qt1.Insert(b.get());
	qt1.Insert(c.get());
	qt1.Insert(d.get());
	auto result = qt1.Search(Point(2, 2));

	if (result)
	{
		std::cout << result->position.x << ", " << result->position.y << " : " << result->data << std::endl;
	}
	else
	{
		std::cout << "Not Found" << std::endl;
	}

	std::vector<int> v{ 1, 2, 3, 4, 5 };

	// C++20
	std::make_heap(v.begin(), v.end());

	for (auto& e : v)
	{
		std::cout << e << std::endl;
	}

	std::cout << "-------------" << std::endl;
	// 정렬

	while (!v.empty())
	{
		std::cout << v.front() << std::endl;
		std::pop_heap(v.begin(), v.end());
		v.pop_back();
	}


	// min heap

	v = { 4, 2, 5, 1, 3 };
	std::make_heap(v.begin(), v.end(), std::greater<>());

	std::cout << "-------------" << std::endl;

	for (auto& e : v)
	{
		std::cout << e << std::endl;
	}
}