#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>


// �Ǻ���ġ
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
// m x n�� �������� �»��->���ϴ����� �̵��ϴ� ��� ����Ǽ�
// �̵��� �������̳� �Ʒ������θ� ���� �ֽ��ϴ�.
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

// ������ �迭 nums���� ���ڵ��� �����Ͽ� sum�� ����� �� �� �ִ��� Ȯ���ϴ� �Լ�
// nums : ����� ����
// sum�� ����� ���� numbers�� ������ ���Ҹ� ������ ��� ����
// ex)
// CanAccumulate(8, {2, 3, 5});
// ��� : ��
// Time Complexity : sum - m, �迭�� ũ�Ⱑ n�̸� O(n^m)
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

// Time Complexity : sum - m, �迭�� ũ�Ⱑ n�̸� O(n * m)
// Space Complexity : O(m + n + m*n) -> O(m) (n�� �����ϴϱ� ���ٸ�)
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

// ������ �迭 nums���� ���ڵ��� �����Ͽ� sum�� ����� �� �� �ִ��� Ȯ���ϴ� �Լ�
// nums : ����� ����
// sum�� ����� ���� numbers�� ������ ���Ҹ� ������ ��� ����
// ex)
// CanAccumulate(8, {2, 3, 5});
// ��� : { 2,2,2,2 } or {3,5} or {2,3,3};
// ����� ������ ��� : nullptr, �Է��� 0�̸� ����� {}
// Time Complexity : sum - m, �迭�� ũ�Ⱑ n�̸� O()
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
// Time Complexity : sum - m, �迭�� ũ�Ⱑ n�̸� O(m*n)
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
			// ���� ���� ������ �̽� ����
			ret->push_back(e);
			h[sum] = ret;
			return h[sum];
		}
	}
	h[sum] = nullptr;
	return h[sum];
}


// ������ �迭 nums���� ���ڵ��� �����Ͽ� sum�� ����� �� �� �ִ� ���� ���յ� 
// �߿� ���Ұ� ���� ���� ���
// nums : ����� ����
// sum�� ����� ���� numbers�� ������ ���Ҹ� ������ ��� ����
// ex)
// MinAccumulate(8, {2, 3, 5});
// ��� : { 2,2,2,2 } or {3,5} or {2,3,3} �߿� ������ {3,5} or {5,3};
// ����� ������ ��� : {}
// Time Complexity : sum - m, �迭�� ũ�Ⱑ n�̸� O(m * n)
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

// ���ڿ� ����--------------------------------------------------------------------- 
// �־��� ���ڿ��� ���� stringList���� target ���ڿ��� ���� �� �ִ°�?
// target�� ����� ���� ������ ���Ҹ� ������ ����ص� �˴ϴ�. 
// target�� �� ���ڿ��̸� ��.
// "abcdef" { "ab", "abc", "cd", "def", "abcd" }

// ����ȭ ���ѹ���. target�� ���� m , list�� ���� ���� n
// Time Complexity :  O(n^m * m)
// Space Complexity : O(m^2)
// ����ȭ ����
// Time Complexity :  O(m * n) -> find �� ����ϸ� O(m^2 * n)
// Space Complexity : O(m^2 + m^2) �����丮������ ������ ��O �� -> O(m^2)
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

// �־��� ���ڿ��� ���� stringList���� target ���ڿ��� ���� �� �ִ� ��� ����� �� ��ȯ
// Time Complexity : O(m^2 * n) 
// Space Complexity : ����
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

// �־��� ���ڿ��� ���� stringList���� target ���ڿ��� ���� �� �ִ� ��� ����� ���� �迭��
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
				retList.push_front(e2); // �̰� ���� �������
			}
		}
	}
	return retList;
}
// ����ȭ ����
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
				retList.push_front(e2); // �̰� ���� �������
			}
		}
	}

	h[target] = retList;
	return h[target];
}