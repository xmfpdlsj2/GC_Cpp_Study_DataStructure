#include <iostream>
//#include "binarytree.h"
#include "BinarySearchTree.h"

int main()
{
	//MyTree::BinaryTree myBTree{};
	//auto pRoot = myBTree.GetRoot();
	//pRoot->mData = 1;

	//auto pNode = myBTree.InsertLeft(pRoot, 2);
	//myBTree.InsertLeft(pNode, 4);
	//myBTree.InsertRight(pNode, 5);

	//pNode = myBTree.InsertRight(pRoot, 3);
	//myBTree.InsertLeft(pNode, 6);
	//myBTree.InsertRight(pNode, 7);

	//myBTree.BreadthFirst();
	//std::cout << std::endl;
	//myBTree.DepthFirst();
	//std::cout << std::endl;
	//myBTree.DepthFirstRecursive(pRoot);
	
	MyTree::BinarySearchTree myBsTree{};
	auto pRoot = myBsTree.GetRoot();
	pRoot->mData = 8;
	
	myBsTree.Insert(pRoot, 3);
	myBsTree.Insert(pRoot, 10);
	myBsTree.Insert(pRoot, 1);
	myBsTree.Insert(pRoot, 6);
	myBsTree.Insert(pRoot, 7);
	myBsTree.InOrder(pRoot);

}
