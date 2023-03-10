#pragma once
#include <iostream>

namespace MyTree
{
	struct Point
	{
		int x;
		int y;
		Point() : Point(0, 0) {}
		Point(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
	};
	
	struct Node
	{
		Point pos;
		int data;

		Node() : Node(Point(), 0) {};
		Node(Point p, int data) 
		{
			this->pos = p;
			this->data = data;
		};
	};

	class QuadTree
	{
		Point topLeft;
		Point bottomRight;
		Node* node; 
		std::unique_ptr<QuadTree> nw;
		std::unique_ptr<QuadTree> ne;
		std::unique_ptr<QuadTree> sw;
		std::unique_ptr<QuadTree> se;

	public:
		QuadTree();
		QuadTree(Point topLeft, Point bottomRight);

		void Insert(Node* node);
		Node* Search(Point pt);
		bool IsInBound(Point pt);
	};
}

