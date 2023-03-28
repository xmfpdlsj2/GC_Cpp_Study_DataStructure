#pragma once
#include <iostream>

namespace MyTree
{
	struct Node
	{
		int mData;
		Node* mLeft;
		Node* mRight;

		Node(int data, Node* left, Node* right)
		{
			mData = data;
			mLeft = left;
			mRight = right;
		}
	};

	class BinarytreeSample
	{
		Node* mpRoot;

	public:
		BinarytreeSample();
		~BinarytreeSample();

		Node* GetRoot() const
		{
			return mpRoot;
		}

		Node* CreateNode(int data);
		Node* InsertLeft(Node* parent, int data);
		Node* InsertRight(Node* parent, int data);

		void Visit(Node* node)
		{
			std::cout << node->mData << " - ";
		}

		void BreadthFirst();
		void DepthFirst();
		void DepthFirstRecursive(Node* pRoot);

		void PreOrder(Node* pNode);
		void InOrder(Node* pNode);
		void PostOrder(Node* pNode);
	};

}

