#pragma once

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
	class BinarySearchTreeSample
	{
		Node* mpRoot;

	public:
		BinarySearchTreeSample();
		Node* GetRoot();
		Node* CreateNode(int data);
		Node* Insert(Node* pParent, int data);

		void Visit(Node* pNode);
		void InOrder(Node* pNode);
	};
}

