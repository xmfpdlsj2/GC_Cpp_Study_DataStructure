#pragma once
#include <iostream>
#include <vector>

namespace MyTree
{
	class Heap
	{
		std::vector<int> mHeap;

	public:
		void Insert(int value);
		void Pop();
		void Print();
	};
}

