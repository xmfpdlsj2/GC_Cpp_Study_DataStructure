#include "BinarySearchTreeSample.h"
#include <iostream>	

namespace MyTree
{
	BinarySearchTreeSample::BinarySearchTreeSample()
	{
		mpRoot = CreateNode(0);
	}
	Node* BinarySearchTreeSample::GetRoot()
	{
		return mpRoot;
	}
	Node* BinarySearchTreeSample::CreateNode(int data)
	{
		return new Node{data, nullptr, nullptr};
	}
	// TimeComplex(O(logn))
	Node* BinarySearchTreeSample::Insert(Node* pParent, int data)
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
	void BinarySearchTreeSample::Visit(Node* pNode)
	{
		std::cout << pNode->mData << "-";
	}
	void BinarySearchTreeSample::InOrder(Node* pNode)
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