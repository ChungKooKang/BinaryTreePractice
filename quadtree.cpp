#include <cmath>

#include "quadtree.h"

QuadTree::QuadTree() : 
	topLeft{ Point()},
	bottomRight{ Point()},
	node { nullptr },
	nw{ nullptr },
	ne{ nullptr },
	sw{ nullptr },
	se{ nullptr }
{
}

QuadTree::QuadTree(Point topLeft, Point bottomRight) : QuadTree()
{
	this->topLeft = topLeft;
	this->bottomRight = bottomRight;
}

void QuadTree::Insert(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	// Check Bound
	if (!IsInBound(node->position))
	{
		return;
	}

	// Base case : 1 x 1
	if (std::abs(bottomRight.x - topLeft.x) <= 1 &&
		std::abs(bottomRight.y - topLeft.y) <= 1)
	{
		if (this->node == nullptr)
		{
			this->node = node;
		}

		return;
	}
	
	// recursive case
	if ( (topLeft.x + bottomRight.x) / 2 >= node->position.x )  //서쪽
	{
		if((topLeft.y + bottomRight.y) / 2 >= node->position.y)	//북서
		{
			if (nw == nullptr)
			{
				nw = std::make_unique<QuadTree>(
					Point(topLeft.x, topLeft.y),
					Point((topLeft.x + bottomRight.x) / 2, (topLeft.y + bottomRight.y) / 2));
			}
			nw->Insert(node);
		}
		else													// 남서
		{
			if (sw == nullptr)
			{
				sw = std::make_unique<QuadTree>(
					Point(topLeft.x, (topLeft.y + bottomRight.y) / 2),
					Point((topLeft.x + bottomRight.x) / 2, bottomRight.y));
			}
			sw->Insert(node);
		}
	}
	else // 동쪽
	{
		if ((topLeft.y + bottomRight.y) / 2 >= node->position.y) //북동
		{
			if (ne == nullptr)
			{
				ne = std::make_unique<QuadTree>(
					Point((topLeft.x + bottomRight.x) / 2, topLeft.y),
					Point(bottomRight.x, (topLeft.y + bottomRight.y) / 2)
					);
			}
			
			ne->Insert(node);
		}
		else													 //남동
		{
			if (se == nullptr)
			{
				se = std::make_unique<QuadTree>(
					Point((topLeft.x + bottomRight.x) / 2, (topLeft.y + bottomRight.y) / 2),
					Point(bottomRight.x, bottomRight.y)
					);

			}
			se->Insert(node);
		}

	}
}

Node* QuadTree::Search(Point pt)
{
	// base case
	if (!IsInBound(pt))
	{
		return nullptr;
	}

	if (node != nullptr)
	{
		return node;
	}

	//recursive case
	if ((topLeft.x + bottomRight.x) / 2 >= pt.x)
	{
		// 서
		if ((topLeft.y + bottomRight.y) / 2 >= pt.y)
		{
			// 북서
			if (nw == nullptr)
			{
				return nullptr;
			}
			nw->Search(pt);
		}
		else
		{
			// 남서
			if (sw == nullptr)
			{
				return nullptr;
			}
			sw->Search(pt);
		}
	}
	else
	{
		// 동
		if ((topLeft.y + bottomRight.y) / 2 >= pt.y)
		{

			// 북동
			if (ne == nullptr)
			{
				return nullptr;
			}
			return ne->Search(pt);
		}
		else
		{
			// 남동
			if (se == nullptr)
			{
				return nullptr;
			}
			return se->Search(pt);

		}

	}
}

bool QuadTree::IsInBound(Point pt)
{
	return (pt.x >= topLeft.x && pt.x <= bottomRight.x) &&
		(pt.y >= topLeft.y && pt.y <= bottomRight.y);
}
