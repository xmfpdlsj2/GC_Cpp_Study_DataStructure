#include "Heap.h"

namespace MyTree
{
	// Time Complexity : O(log n)
	// Space Complexity : O(n)
	void Heap::Insert(int value)
	{
		mHeap.push_back(value);

		int i = static_cast<int>(mHeap.size()) - 1;
		int half = (i - 1) / 2;
		
		while (i != 0 && value >= mHeap[half])
		{
			std::swap(mHeap[i], mHeap[half]);
			i = half;
			half = (i - 1) / 2;
		}
	}
	void Heap::Pop()
	{
		if (mHeap.size() == 0)
		{
			return;
		}

		int item = mHeap.front();
		std::cout << item << "";
		mHeap[0] = mHeap.back();
		mHeap.pop_back();

		int i{};
		while (i < mHeap.size())
		{
			int big_child = (i * 2) + 1;
			if (big_child >= mHeap.size())
			{
				break;
			}
			if (big_child + 1 < mHeap.size() && mHeap[big_child] < mHeap[big_child + 1])
			{
				big_child++;
			}
			
			if (mHeap[i] >= mHeap[big_child])
			{
				break;
			}
			std::swap(mHeap[i], mHeap[big_child]);
			i = big_child;
		}
	}
	void Heap::Print()
	{
		for (auto& e : mHeap)
		{
			std::cout << e << " ";
		}
	}
}