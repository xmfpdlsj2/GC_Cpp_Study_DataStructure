#include <queue>
#include <stack>
#include "binarytree.h"

namespace MyTree
{
	BinaryTree::BinaryTree()
	{
		mpRoot = CreateNode(0);
	}
	BinaryTree::~BinaryTree()
	{
	}
	Node* BinaryTree::CreateNode(int data)
	{
		return new Node{data, nullptr, nullptr};
	}
	Node* BinaryTree::InsertLeft(Node* parent, int data)
	{
		parent->mLeft = CreateNode(data);
		return parent->mLeft;
	}
	Node* BinaryTree::InsertRight(Node* parent, int data)
	{
		parent->mRight = CreateNode(data);
		return parent->mRight;
	}
	// TimeComplex O(n)
	// SpaceComplex O(n)
	void BinaryTree::BreadthFirst()
	{
		std::queue<Node*> q;
		q.push(mpRoot);

		while (!q.empty())
		{
			auto node = q.front();
			Visit(node);
			q.pop();

			if (node->mLeft != nullptr)
			{
				q.push(node->mLeft);
			}
			if (node->mRight != nullptr)
			{
				q.push(node->mRight);
			}
		}
	}
	// TimeComplex O(n)
	// SpaceComplex O(n)
	void BinaryTree::DepthFirst()
	{
		std::stack<Node*> s;
		s.push(mpRoot);

		while (!s.empty())
		{
			auto node = s.top();
			Visit(node);
			s.pop();

			if (node->mRight)
			{
				s.push(node->mRight);
			}
			if (node->mLeft)
			{
				s.push(node->mLeft);
			}
		}
	}
	// TimeComplex O(n)
	// SpaceComplex O(n)
	void BinaryTree::DepthFirstRecursive(Node* pRoot)
	{
		if (pRoot == nullptr)
		{
			return;
		}

		Visit(pRoot);
		DepthFirstRecursive(pRoot->mLeft);
		DepthFirstRecursive(pRoot->mRight);
		return;
	}
	void BinaryTree::PreOrder(Node* pNode)
	{
		if (!pNode)
		{
			return;
		}

		Visit(pNode);
		PreOrder(pNode->mLeft);
		PreOrder(pNode->mRight);
	}
	void BinaryTree::InOrder(Node* pNode)
	{
		if (!pNode)
		{
			return;
		}

		InOrder(pNode->mLeft);
		Visit(pNode);
		InOrder(pNode->mRight);
	}
	void BinaryTree::PostOrder(Node* pNode)
	{
		if (!pNode)
		{
			return;
		}

		PostOrder(pNode->mLeft);
		PostOrder(pNode->mRight);
		Visit(pNode);
	}
}