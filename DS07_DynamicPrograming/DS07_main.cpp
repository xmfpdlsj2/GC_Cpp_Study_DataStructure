#include "Ex1.h"

void Print(std::shared_ptr<std::vector<int>> result)
{
	if (result == nullptr)
	{
		std::cout << "nullptr" << std::endl;
		return;
	}
	std::cout << "{ ";
	for (auto& e : *result)
	{
		std::cout << e << ", ";
	}
	std::cout << "}";
}

int main()
{
	// Ex 1
	//std::cout << Fibonacci(50) << std::endl;
	//std::map<int, int64_t> h{};
	//std::cout << FibonacciOPT(50, h) << std::endl;

	//std::cout << FindPath(3, 3) << std::endl;
	//path_h h{};
	//std::cout << FindPathOPT(20, 20, h) << std::endl;

	//std::cout << CanAccumulate(7, { 2, 4 }) << std::endl;
	//std::map<int, bool> h{};
	//h.clear();
	//std::cout << CanAccumulateOPT(70007, { 2, 4 }, h) << std::endl;

	////Print(HowAccumulate(8, { 2, 3, 5 }));
	//std::map <int, std::shared_ptr<std::vector<int>>> h{};
	//h.clear();
	////Print(HowAccumulateOPT(8, { 2, 3, 5 }, h));
	//Print(MinAccumulate(8, { 2, 3, 5 }, h));
	//Print(MinAccumulate(720, { 10, 50, 100, 500 }, h));
	

	//std::map<std::string, bool> h;
	//h.clear();
	//std::cout << CanStringGenerate("abcf", { "ab", "abc", "cd", "def", "abcd" }, h) << std::endl;
	std::map<std::string, int> h;
	std::cout << CombStringGenerate("abcdef", { "ab", "abc", "cd", "def", "cdef" }, h) << std::endl;
}

