#pragma once
#include <iostream>
#include <queue>

namespace BT
{
	struct Node
	{
		int val{};
		Node* left{};
		Node* right{};

		Node() : Node(0) {}
		Node(int val) : val{ val }, left{ nullptr}, right{ nullptr } {}
		Node(int val, Node* left) : val{ val }, left{ left }, right{ nullptr } {}
		Node(int val, Node* left, Node* right) : val{ val }, left{ left }, right{ right } {}
	};

	class BinaryTree
	{
	protected:
		std::queue<Node*> mInsertNQ;
		Node* mpRoot;

	public:
		BinaryTree() : BinaryTree(0) {};
		BinaryTree(int val);
		~BinaryTree();

		Node* GetRoot() const;
		void DeleteAll(Node* pNode);

		virtual void Insert(int val);

		void PreOrder(Node* pNode);
		void InOrder(Node* pNode);
		void PostOrder(Node* pNode);
	
	protected:
		Node* CreateNode(int val);
		void Visit(Node* node) const;

	};
}
