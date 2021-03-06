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
	if ( (topLeft.x + bottomRight.x) / 2 >= node->position.x )  //????
	{
		if((topLeft.y + bottomRight.y) / 2 >= node->position.y)	//?ϼ?
		{
			if (nw == nullptr)
			{
				nw = std::make_unique<QuadTree>(
					Point(topLeft.x, topLeft.y),
					Point((topLeft.x + bottomRight.x) / 2, (topLeft.y + bottomRight.y) / 2));
			}
			nw->Insert(node);
		}
		else													// ????
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
	else // ????
	{
		if ((topLeft.y + bottomRight.y) / 2 >= node->position.y) //?ϵ?
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
		else													 //????
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
		// ??
		if ((topLeft.y + bottomRight.y) / 2 >= pt.y)
		{
			// ?ϼ?
			if (nw == nullptr)
			{
				return nullptr;
			}
			nw->Search(pt);
		}
		else
		{
			// ????
			if (sw == nullptr)
			{
				return nullptr;
			}
			sw->Search(pt);
		}
	}
	else
	{
		// ??
		if ((topLeft.y + bottomRight.y) / 2 >= pt.y)
		{

			// ?ϵ?
			if (ne == nullptr)
			{
				return nullptr;
			}
			return ne->Search(pt);
		}
		else
		{
			// ????
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
