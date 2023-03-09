#include "BinarySearchTree.h"
#include <iostream>	

namespace MyTree
{
	BinarySearchTree::BinarySearchTree()
	{
		mpRoot = CreateNode(0);
	}
	Node* BinarySearchTree::GetRoot()
	{
		return mpRoot;
	}
	Node* BinarySearchTree::CreateNode(int data)
	{
		return new Node{data, nullptr, nullptr};
	}
	// TimeComplex(O(logn))
	Node* BinarySearchTree::Insert(Node* pParent, int data)
	{
		if (pParent == nullptr)
		{
			return CreateNode(data);
		}

		if (data < pParent->mData)
		{
			pParent->mLeft = Insert(pParent->mLeft, data);
		}
		else
		{
			pParent->mRight = Insert(pParent->mRight, data);
		}
		return pParent;
	}
	void BinarySearchTree::Visit(Node* pNode)
	{
		std::cout << pNode->mData << "-";
	}
	void BinarySearchTree::InOrder(Node* pNode)
	{
		if (!pNode)
		{
			return;
		}
		InOrder(pNode->mLeft);
		Visit(pNode);
		InOrder(pNode->mRight);
	}
}