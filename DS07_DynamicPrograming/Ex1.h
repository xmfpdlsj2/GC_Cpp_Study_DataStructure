#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>


// 피보나치
// Time Complexity O(2^n)
// Space Complexity O(n)
int Fibonacci(int n)
{
	if (n <= 2)
	{
		return 1;
	}

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
// Time Complexity O(n)
// Space Complexity O(n)
int64_t FibonacciOPT(int n, std::map<int, int64_t>& history)
{
	if (history.count(n) == 1)
	{
		return history[n];
	}

	if (n <= 2)
	{
		return 1;
	}

	history[n] = FibonacciOPT(n - 1, history) + FibonacciOPT(n - 2, history);
	return history[n];
}



// Find Path
// m x n의 영역에서 좌상단->우하단으로 이동하는 모든 경우의수
// 이동은 오른쪽이나 아래쪽으로만 갈수 있습니다.
// Time Complexity O(2^(m+n))
// Space Complexity O(m+n)
int FindPath(int m, int n)
{
	if (m == 0 || n == 0)
	{
		return 0;
	}
	if (m == 1 && n == 1)
	{
		return 1;
	}

	return FindPath(m - 1, n) + FindPath(m, n - 1);
}
// Time Complexity O(m * n))
// Space Complexity O(m+n)
using path_h = std::map<std::string, int>;
int FindPathOPT(int m, int n, path_h& history)
{
	const std::string key = std::to_string(m) + "," + std::to_string(n);
	if (history.count(key) == 1)
	{
		return history[key];
	}
	const std::string rKey = std::to_string(n) + "," + std::to_string(m);
	if (history.count(rKey) == 1)
	{
		return history[rKey];
	}

	if (m == 0 || n == 0)
	{
		return 0;
	}
	if (m == 1 && n == 1)
	{
		return 1;
	}

	history[key] = FindPathOPT(m - 1, n, history) + FindPathOPT(m, n - 1, history);
	return history[key];
}

// 정수의 배열 nums에서 숫자들을 조합하여 sum을 만들어 낼 수 있는지 확인하는 함수
// nums : 양수의 집합
// sum을 만들기 위해 numbers의 동일한 원소를 여러번 사용 가능
// ex)
// CanAccumulate(8, {2, 3, 5});
// 출력 : 참
// Time Complexity : sum - m, 배열의 크기가 n이면 O(n^m)
// Space Complexity : O(m + n)
bool CanAccumulate(int sum, const std::vector<int>& nums)
{
	if (sum == 0)
	{
		return true;
	}
	if (sum < 0)
	{
		return false;
	}

	for (auto& e : nums)
	{
		if (CanAccumulate(sum - e, nums))
		{
			return true;
		}
	}
	return false;
}

// Time Complexity : sum - m, 배열의 크기가 n이면 O(n * m)
// Space Complexity : O(m + n + m*n) -> O(m) (n은 동일하니까 뺀다면)
bool CanAccumulateOPT(int sum, const std::vector<int>& nums,
	std::map<int, bool>& h)
{
	if (h.count(sum) == 1)
	{
		return h[sum];
	}
	if (sum == 0)
	{
		return true;
	}
	if (sum < 0)
	{
		return false;
	}

	for (auto& e : nums)
	{
		if (CanAccumulateOPT(sum - e, nums, h))
		{
			h[sum] = true;
			return h[sum];
		}
	}
	h[sum] = false;
	return h[sum];
}

// 정수의 배열 nums에서 숫자들을 조합하여 sum을 만들어 낼 수 있는지 확인하는 함수
// nums : 양수의 집합
// sum을 만들기 위해 numbers의 동일한 원소를 여러번 사용 가능
// ex)
// CanAccumulate(8, {2, 3, 5});
// 출력 : { 2,2,2,2 } or {3,5} or {2,3,3};
// 만들수 없을때 출력 : nullptr, 입력이 0이면 출력은 {}
// Time Complexity : sum - m, 배열의 크기가 n이면 O()
// Space Complexity : O()
std::shared_ptr<std::vector<int>> HowAccumulate(int sum, const std::vector<int>& nums)
{
	if (sum == 0)
	{
		return std::make_shared<std::vector<int>>();
	}
	if (sum < 0)
	{
		return nullptr;
	}

	for (auto& e : nums)
	{
		auto ret = HowAccumulate(sum - e, nums);
		if (ret)
		{
			ret->push_back(e);
			return ret;
		}
	}
	return nullptr;
}
// Time Complexity : sum - m, 배열의 크기가 n이면 O(m*n)
// Space Complexity : O(m^2 * n)
std::shared_ptr<std::vector<int>> HowAccumulateOPT(int sum, const std::vector<int>& nums,
std::map<int, std::shared_ptr<std::vector<int>>>& h)
{
	if (h.count(sum) == 1)
	{
		return h[sum];
	}
	if (sum == 0)
	{
		return std::make_shared<std::vector<int>>();
	}
	if (sum < 0)
	{
		return nullptr;
	}

	for (auto& e : nums)
	{
		auto ret = HowAccumulateOPT(sum - e, nums, h);
		if (ret)
		{
			// 여기 복사 생성자 이슈 있음
			ret->push_back(e);
			h[sum] = ret;
			return h[sum];
		}
	}
	h[sum] = nullptr;
	return h[sum];
}


// 정수의 배열 nums에서 숫자들을 조합하여 sum을 만들어 낼 수 있는 숫자 집합들 
// 중에 원소가 가장 적은 결과
// nums : 양수의 집합
// sum을 만들기 위해 numbers의 동일한 원소를 여러번 사용 가능
// ex)
// MinAccumulate(8, {2, 3, 5});
// 출력 : { 2,2,2,2 } or {3,5} or {2,3,3} 중에 정답은 {3,5} or {5,3};
// 만들수 없을때 출력 : {}
// Time Complexity : sum - m, 배열의 크기가 n이면 O(m * n)
// Space Complexity : O(m^2 * n)
std::shared_ptr<std::vector<int>> MinAccumulate(int sum, const std::vector<int>& nums,
	std::map<int, std::shared_ptr<std::vector<int>>>& h)
{
	if (h.count(sum) == 1)
	{
		return h[sum];
	}
	if (sum < 0)
	{
		return nullptr;
	}
	if (sum == 0)
	{
		return std::make_shared<std::vector<int>>();
	}

	std::shared_ptr<std::vector<int>> min{};
	for (auto& e : nums)
	{
		auto ret = MinAccumulate(sum - e, nums, h);
		if (ret)
		{
			std::shared_ptr<std::vector<int>> v = std::make_shared<std::vector<int>>();
			v->resize(ret->size());
			std::copy(ret->begin(), ret->end(), v->begin());

			v->push_back(e);
			if (min == nullptr || v->size() < min->size())
			{
				min = v;
			}
		}
	}
	h[sum] = min;
	return h[sum];
}

// 문자열 문제--------------------------------------------------------------------- 
// 주어진 문자열의 집합 stringList에서 target 문자열을 만들 수 있는가?
// target을 만들기 위해 동일한 원소를 여러번 사용해도 됩니다. 
// target이 빈 문자열이면 참.
// "abcdef" { "ab", "abc", "cd", "def", "abcd" }

// 최적화 안한버전. target의 길이 m , list의 원소 갯수 n
// Time Complexity :  O(n^m * m)
// Space Complexity : O(m^2)
// 최적화 버전
// Time Complexity :  O(m * n) -> find 도 고려하면 O(m^2 * n)
// Space Complexity : O(m^2 + m^2) 히스토리때문에 하지만 빅O 라서 -> O(m^2)
bool CanStringGenerate(std::string target, const std::vector<std::string>& list,
	std::map<std::string, bool>& h)
{
	if (h.count(target) == 1)
	{
		return h[target];
	}
	if (target.length() <= 0)
	{
		return true;
	}

	for (auto& e : list)
	{
		if (target.find(e) == 0)
		{
			auto ret = target.substr(e.length());
			if (CanStringGenerate(ret, list, h))
			{
				h[target] = true;
				return h[target];
			}
		}
	}
	h[target] = false;
	return h[target];
}

// 주어진 문자열의 집합 stringList에서 target 문자열을 만들 수 있는 모든 경우의 수 반환
// Time Complexity : O(m^2 * n) 
// Space Complexity : 동일
int CombStringGenerate(std::string target, const std::vector<std::string>& list,
	std::map<std::string, int>& h)
{
	if (h.count(target) == 1)
	{
		return h[target];
	}

	if (target.length() <= 0)
	{
		return 1;
	}

	int ret{};
	for (auto& e : list)
	{
		if (target.find(e) == 0)
		{
			auto sub = target.substr(e.length());
			ret += CombStringGenerate(sub, list, h);
		}
	}
	h[target] = ret;
	return h[target];
}

// 주어진 문자열의 집합 stringList에서 target 문자열을 만들 수 있는 모든 경우의 수를 배열로
// Time Complexity : O(n^m * m)
// Space Complexity : O(m^2 + m * n) -> O(m^2)
std::list<std::list<std::string>> ListStringGenerate(
	std::string target, const std::vector<std::string>& list)
{
	if (target.length() <= 0)
	{
		return std::list<std::list<std::string>>{ {} };
	}

	std::list<std::list<std::string>> retList{};
	for (auto& e : list)
	{
		if (target.find(e) == 0)
		{
			auto sub = target.substr(e.length());
			auto ret = ListStringGenerate(sub, list);

			for (auto e2 : ret)
			{
				e2.push_front(e);
				retList.push_front(e2); // 이건 순서 상관없음
			}
		}
	}
	return retList;
}
// 최적화 버전
// Time Complexity : O(n^m)
// Space Complexity :O(m^2 + m * n) -> O(m^2)
std::list<std::list<std::string>> ListStringGenerateOPT(
	std::string target, const std::vector<std::string>& list,
	std::map<std::string, std::list<std::list<std::string>>> h)
{
	if (h.count(target)== 1)
	{
		return h[target];
	}

	if (target.length() <= 0)
	{
		return std::list<std::list<std::string>>{ {} };
	}

	std::list<std::list<std::string>> retList{};
	for (auto& e : list)
	{
		if (target.find(e) == 0)
		{
			auto sub = target.substr(e.length());
			auto ret = ListStringGenerateOPT(sub, list, h);

			for (auto e2 : ret)
			{
				e2.push_front(e);
				retList.push_front(e2); // 이건 순서 상관없음
			}
		}
	}

	h[target] = retList;
	return h[target];
}