#include <iostream>
#include "QuadTree.h"

using namespace MyTree;

int main()
{
	MyTree::QuadTree myTree{ Point(0,0), Point(8,8) };
	std::unique_ptr<Node> a = std::make_unique<Node>(Point(1, 1), 1);
	std::unique_ptr<Node> b = std::make_unique<Node>(Point(2, 2), 2);
	myTree.Insert(a.get());
	myTree.Insert(b.get());

	std::cout << "2,2 : " << myTree.Search(Point(2, 2))->data << std::endl;
}
