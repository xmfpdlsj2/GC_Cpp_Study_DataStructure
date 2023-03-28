#include <queue>
#include <stack>
#include "BinarytreeSample.h"

namespace MyTree
{
	BinarytreeSample::BinarytreeSample()
	{
		mpRoot = CreateNode(0);
	}
	BinarytreeSample::~BinarytreeSample()
	{
	}
	Node* BinarytreeSample::CreateNode(int data)
	{
		return new Node{data, nullptr, nullptr};
	}
	Node* BinarytreeSample::InsertLeft(Node* parent, int data)
	{
		parent->mLeft = CreateNode(data);
		return parent->mLeft;
	}
	Node* BinarytreeSample::InsertRight(Node* parent, int data)
	{
		parent->mRight = CreateNode(data);
		return parent->mRight;
	}
	// TimeComplex O(n)
	// SpaceComplex O(n)
	void BinarytreeSample::BreadthFirst()
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
	void BinarytreeSample::DepthFirst()
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
	void BinarytreeSample::DepthFirstRecursive(Node* pRoot)
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
	void BinarytreeSample::PreOrder(Node* pNode)
	{
		if (!pNode)
		{
			return;
		}

		Visit(pNode);
		PreOrder(pNode->mLeft);
		PreOrder(pNode->mRight);
	}
	void BinarytreeSample::InOrder(Node* pNode)
	{
		if (!pNode)
		{
			return;
		}

		InOrder(pNode->mLeft);
		Visit(pNode);
		InOrder(pNode->mRight);
	}
	void BinarytreeSample::PostOrder(Node* pNode)
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