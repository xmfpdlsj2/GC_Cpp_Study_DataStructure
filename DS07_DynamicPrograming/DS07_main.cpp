#include "Ex1.h"
#include "Ex2.h"

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

void Print(std::list<std::list<std::string>>& result)
{
	std::cout << "{" << std::endl;
	for (auto& e1 : result)
	{
		std::cout << "\t{ ";
		for (auto& e2 : e1)
		{
			std::cout << e2 << ", ";
		}
		std::cout << "}," << std::endl;

	}
	std::cout << "}" << std::endl;
}

void DynamicProgramming01()
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
	//std::map<std::string, int> h;
	//std::cout << CombStringGenerate("abcdef", { "ab", "abc", "cd", "def", "cdef" }, h) << std::endl;
		auto ls = ListStringGenerate("hello", { "h", "e", "he", "llo", "hell" });
		Print(ls);

		std::map<std::string, std::list<std::list<std::string>>> h{};
		h.clear();
		auto lsOPT = ListStringGenerateOPT("hello", { "h", "e", "he", "llo", "hell" }, h);
		Print(lsOPT);
}

void DynamicProgramming02()
{
	//std::cout << Fibonacci02OPT(50) << std::endl;
	
	//std::cout << FindPath02(5,6) << std::endl;

	//std::cout << CanAccumulate02(12, { 3,5 }) << std::endl;
	//Print(HowAccumulate02(12, { 3,5 }));
	//Print(MinAccumulate02(8, { 2,3,5 }));

	//std::cout << CanStringGenerate02("abcdef" ,{"ab", "abc", "cd", "def", "abcd"});
	std::cout << CombStringGenerate02("hello" ,{"h", "he", "llo", "hell", "o", "lo", "hel", "e"});
}
int main()
{
	//DynamicProgramming01();
	DynamicProgramming02();
}

