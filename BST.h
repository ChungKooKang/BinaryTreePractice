#pragma once

#include <iostream>

namespace mytree
{
	struct Node
	{
		int mData;
		Node* mpLeft;
		Node* mpRight;
		Node(int data, Node* pLeft, Node* pRight)
		{
			mData = data;
			mpLeft = pLeft;
			mpRight = pRight;
		}
	};

	class BinarySearchTree
	{
	private :
		Node* mpRoot{};

	public :
		BinarySearchTree()
		{
			mpRoot = CreateNode(0);
		}

		Node* CreateNode(int data)
		{
			return new Node(data, nullptr, nullptr);
		}

		Node* GetRoot() const
		{
			return mpRoot;
		}

		Node* Insert(Node* pParent, int data)
		{
			//base case
			if (pParent == nullptr)
			{
				return CreateNode(data);
			}

			//recursive case
			if (data < pParent->mData)
			{
				pParent->mpLeft = Insert(pParent->mpLeft, data);
			}
			else if (data > pParent-> mData)
			{
				pParent->mpRight = Insert(pParent->mpRight, data);
			}

			return pParent;
		}
	public :
		void Visit(Node* pNode)
		{
			std::cout << ;
		}

		void PreOrder(Node* pNode)
		{
			if (pNode == nullptr)
			{
				returnl
			}

			PreOrder(pNode->mpLeft);
			PreOrder(pNode->mpRight);
		}
		void InOrder(Node* pNode)
		{
			if (pNode == nullptr)
			{
				returnl
			}

			PreOrder(pNode->mpLeft);
			PreOrder(pNode->mpRight);
		}
		void PreOrder(Node* pNode)
		{
			if (pNode == nullptr)
			{
				returnl
			}

			PreOrder(pNode->mpLeft);
			PreOrder(pNode->mpRight);
		}
	};
}