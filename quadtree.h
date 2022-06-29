#pragma once

#include <memory>


struct Point
{
	int x;
	int y;

	Point() : x{ 0 }, y{ 0 }
	{

	}

	Point(int x, int y) : x{ x }, y{ y }	// x(member){x(parameter)}
	{
	}
};

struct Node
{
	Point position;
	int data;

	Node() : position{}, data{}
	{

	}
	Node(const Point& p, int data)
	{
		this->position = p;
		this->data = data;
	}
};

class QuadTree
{
private :
	// Rectangle
	Point topLeft;
	Point bottomRight;

	// Current  Node
	Node* node;

	// Sub QuadTree
	std::unique_ptr<QuadTree> nw;
	std::unique_ptr<QuadTree> ne;
	std::unique_ptr<QuadTree> sw;
	std::unique_ptr<QuadTree> se;

public :
	QuadTree();
	QuadTree(Point topleft, Point bottomRight);
	void Insert(Node* node);
	Node* Search(Point pt);

	bool IsInBound(Point pt);
};