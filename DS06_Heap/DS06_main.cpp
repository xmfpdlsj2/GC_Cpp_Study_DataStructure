#include <iostream>
#include "Heap.h"

int main()
{
	MyTree::Heap myHeap;
	myHeap.Insert(1);
	myHeap.Insert(2);
	myHeap.Insert(3);
	myHeap.Insert(4);
	myHeap.Insert(5);
	myHeap.Print();
	std::cout << std::endl;
	myHeap.Pop();
	myHeap.Pop();
	myHeap.Pop();
	myHeap.Pop();
	myHeap.Pop();
	myHeap.Pop();
	myHeap.Pop();
}
