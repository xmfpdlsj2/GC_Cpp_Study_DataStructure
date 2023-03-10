#include "QuadTree.h"

namespace MyTree
{
	QuadTree::QuadTree() : topLeft{}, bottomRight{}, node{},
		nw{}, ne{}, sw{}, se{}
	{
	}
	QuadTree::QuadTree(Point topLeft, Point bottomRight) : QuadTree()
	{
		this->topLeft = topLeft;
		this->bottomRight = bottomRight;
	}
	void QuadTree::Insert(Node* node)
	{
		if (!node)
		{
			return;
		}
		if (!IsInBound(node->pos))
		{
			return;
		}
		if (std::abs(topLeft.x - bottomRight.x) <= 1 &&
			std::abs(topLeft.y - bottomRight.y) <= 1)
		{
			if (this->node == nullptr)
			{
				this->node = node;
			}
			return;
		}

		if ((topLeft.x + bottomRight.x) / 2 >= node->pos.x)
		{
			if ((topLeft.y + bottomRight.y) / 2 >= node->pos.y)
			{
				if (!nw)
				{
					nw = std::make_unique<QuadTree>(
						Point(topLeft.x, topLeft.y),
						Point((topLeft.x + bottomRight.x) / 2,
							(topLeft.y + bottomRight.y) / 2)
						);
				}
				nw->Insert(node);
			}
			else
			{
				if (!sw)
				{
					sw = std::make_unique<QuadTree>(
						Point(topLeft.x, (topLeft.y + bottomRight.y) / 2),
						Point((topLeft.x + bottomRight.x) / 2, bottomRight.y)
						);
				}
				sw->Insert(node);
			}
		}
		else
		{
			if ((topLeft.y + bottomRight.y) / 2 >= node->pos.y)
			{
				if (!ne)
				{
					ne = std::make_unique<QuadTree>(
						Point((topLeft.x + bottomRight.x) / 2, topLeft.y),
						Point(bottomRight.x, (topLeft.y + bottomRight.y) /2)
						);
				}
				ne->Insert(node);
			}
			else
			{
				if (!se)
				{
					se = std::make_unique<QuadTree>(
						Point((topLeft.x + bottomRight.x) / 2,
							(topLeft.y + bottomRight.y) / 2),
						Point(bottomRight.x, bottomRight.y)
						);
				}
				se->Insert(node);
			}
		}
	}
	Node* QuadTree::Search(Point pt)
	{
		if (!IsInBound(pt))
		{
			return nullptr;
		}
		if (node)
		{
			return node;
		}

		if ((topLeft.x + bottomRight.x) / 2 >= pt.x)
		{
			if ((topLeft.y + bottomRight.y) / 2 >= pt.y)
			{
				if (!nw)
				{
					return nullptr;
				}
				return nw->Search(pt);
			}
			else
			{
				if (!sw)
				{
					return nullptr;
				}
				return sw->Search(pt);
			}
		}
		else
		{
			if ((topLeft.y + bottomRight.y) / 2 >= pt.y)
			{
				if (!ne)
				{
					return nullptr;
				}
				return ne->Search(pt);
			}
			else
			{
				if (!se)
				{
					return nullptr;
				}
				return se->Search(pt);
			}
		}
	}
	bool QuadTree::IsInBound(Point pt)
	{
		return (pt.x >= topLeft.x && pt.x <= bottomRight.x &&
				pt.y >= topLeft.y && pt.y <= bottomRight.y);
	}
}