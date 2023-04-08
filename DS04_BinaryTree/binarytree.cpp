#include "BinaryTree.h"

namespace BT
{
	BT::BinaryTree::BinaryTree(int val)
	{
		mpRoot = CreateNode(val);
		mInsertNQ.push(mpRoot);
	}

	BT::BinaryTree::~BinaryTree()
	{
		DeleteAll(mpRoot);
	}

	Node* BT::BinaryTree::GetRoot() const
	{
		return mpRoot;
	}

	void BinaryTree::DeleteAll(Node* pNode)
	{
		if (!pNode)
		{
			return;
		}
		InOrder(pNode->left);
		InOrder(pNode->right);
		delete pNode;
	}

	void BT::BinaryTree::Insert(int val)
	{
		Node* root{ nullptr };

		while (true)
		{
			root = mInsertNQ.front();
			if (!root)
			{
				break;
			}
			if (root->left && root->right)
			{
				mInsertNQ.pop();
			}
			else if (!root->left)
			{
				root->left = CreateNode(val);
				mInsertNQ.push(root->left);
				break;
			}
			else
			{
				root->right = CreateNode(val);
				mInsertNQ.push(root->right);
				break;
			}
		}
	}

	void BinaryTree::PreOrder(Node* pNode)
	{
		if (!pNode)
		{
			return;
		}
		Visit(pNode);
		PreOrder(pNode->left);
		PreOrder(pNode->right);
	}

	void BinaryTree::InOrder(Node* pNode)
	{
		if (!pNode)
		{
			return;
		}
		InOrder(pNode->left);
		Visit(pNode);
		InOrder(pNode->right);
	}

	void BinaryTree::PostOrder(Node* pNode)
	{
		if (!pNode)
		{
			return;
		}
		PostOrder(pNode->left);
		PostOrder(pNode->right);
		Visit(pNode);
	}

	Node* BT::BinaryTree::CreateNode(int val)
	{
		return new Node{ val };
	}

	void BT::BinaryTree::Visit(Node* node) const
	{
		std::cout << node->val << "-";
	}


}
