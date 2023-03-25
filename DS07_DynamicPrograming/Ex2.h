#pragma once
#include <vector>

// 피보나치 
// F(n) = F(n-1) + F(n-2)
// F(0) = 0, F(1) = 1
// Time Complexity O(n)
// Space Complexity O(n)
int64_t Fibonacci02(int n)
{
	std::vector<int64_t> table{};
	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
		{
			table[i] = 0;
		}
		else if (i == 1)
		{
			table[i] = 1;
		}

		table[i] = table[i - 1] + table[i - 2];
	}

	return table[n];
}
// Time Complexity O(n)
// Space Complexity O(n)
int64_t Fibonacci02OPT(int n)
{
	if (n == 0)
	{
		return 0;
	}
	std::vector<int64_t> table(n+1);
	table[0] = 0;
	table[1] = 1;

	for (int i = 0; i <= n; i++)
	{
		if (i + 1 <= n)
		{
			table[i + 1] += table[i];
		}
		if (i + 2 <= n)
		{
			table[i + 2] += table[i];
		}
	}
	return table[n];
}

// Find Path
// m x n의 영역에서 좌상단->우하단으로 이동하는 모든 경우의수
// 이동은 오른쪽이나 아래쪽으로만 갈수 있습니다.
// Time Complexity O(m*n)
// Space Complexity O(m*n)
int FindPath02(int m, int n)
{
	std::vector<std::vector<int>> grid(m + 1, std::vector<int>(n + 1, 0));

	grid[1][1] = 1;

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if ((i + 1) <= m )
			{
				grid[i + 1][j] += grid[i][j];
			}
			if ((j + 1) <= n)
			{
				grid[i][j + 1] += grid[i][j];
			}
		}
	}

	return grid[m][n];
}

// 정수의 배열 nums에서 숫자들을 조합하여 sum을 만들어 낼 수 있는지 확인하는 함수
// CanAccumulate02(8, {2, 3, 5});
// Time Complexity O(m*n)
// Space Complexity O(m)
bool CanAccumulate02(int sum, const std::vector<int>& nums)
{
	std::vector<bool> table(sum + 1, false);
	table[0] = true;

	for (int i = 0; i <= sum; i++)
	{
		if (table[i])
		{
			for (int j = 0; j < nums.size(); j++)
			{
				if (i + nums[j] < table.size())
				{
					table[i + nums[j]] = true;
				}
			}
		}
	}

	return table[sum];
}

// 정수의 배열 nums에서 숫자들을 조합하여 sum을 만들어 낼 수 있는지 확인하는 함수
// Time Complexity O(m^2*n)
// Space Complexity O(m^2)
std::shared_ptr<std::vector<int>> HowAccumulate02(int sum, const std::vector<int>& nums)
{
	std::vector<std::shared_ptr<std::vector<int>>> table(sum + 1, nullptr);

	table[0] = std::make_shared<std::vector<int>>(0);

	for (int i = 0; i <= sum; i++)
	{
		if (table[i])
		{
			for (auto& e : nums)
			{
				if (i + e <= sum)
				{
					// 복사생성자로 새로 만들어줌
					table[i + e] = std::make_shared<std::vector<int>>(*table[i]);
					table[i + e]->push_back(e);
				}
			}
		}
	}
	return table[sum];
}

// 정수의 배열 nums에서 숫자들을 조합하여 sum을 만들어 낼 수 있는 숫자 집합들 
// 중에 원소가 가장 적은 결과
// Time Complexity O(m^2*n)
// Space Complexity O(m^2)
std::shared_ptr<std::vector<int>> MinAccumulate02(int sum, const std::vector<int>& nums)
{
	std::vector<std::shared_ptr<std::vector<int>>> table(sum + 1, nullptr);

	table[0] = std::make_shared<std::vector<int>>(0);

	for (int i = 0; i <= sum; i++)
	{
		if (table[i])
		{
			for (auto& e : nums)
			{
				// 배열 인덱스 연산 : 범위보장
				// 포인터 널참조 주의
				if (i + e <= sum)
				{
					if (table[i+e] == nullptr || table[i]->size() < table[i + e]->size() - 1)
					{
						table[i + e] = std::make_shared<std::vector<int>>(*table[i]);
						table[i + e]->push_back(e);
					}
				}
			}
		}
	}
	return table[sum];
}

// 문자열 문제--------------------------------------------------------------------- 
// 주어진 문자열의 집합 stringList에서 target 문자열을 만들 수 있는가?
// target을 만들기 위해 동일한 원소를 여러번 사용해도 됩니다. 
// target이 빈 문자열이면 참.
// Time Complexity O(m^2 * n)
// Space Complexity O(m)
bool CanStringGenerate02(std::string target, const std::vector<std::string>& list)
{
	std::vector<bool> table(target.size() + 1, false);

	table[0] = true;

	for (int i = 0; i < target.size(); i++)
	{
		if (table[i])
		{
			for (auto& e : list)
			{
				if (target.substr(i, e.size()) == e)
				{
					if (i + e.size() <= target.size())
					{
						table[i + e.size()] = true;
					}
				}
			}
		}
	}
	return table[target.size()];
}

// 주어진 문자열의 집합 stringList에서 target 문자열을 만들 수 있는 모든 경우의 수 반환
// Time Complexity O(m^2 * n)
// Space Complexity O(m)
int CombStringGenerate02(std::string target, const std::vector<std::string>& list)
{
	std::vector<int> table(target.size() + 1, false);

	table[0] = 1;

	for (int i = 0; i < target.size(); i++)
	{
		if (table[i])
		{
			for (auto& e : list)
			{
				if (target.substr(i, e.size()) == e)
				{
					if (i + e.size() <= target.size())
					{
						table[i + e.size()] += table[i];
					}
				}
			}
		}
	}
	return table[target.size()];
}
// 주어진 문자열의 집합 stringList에서 target 문자열을 만들 수 있는 모든 경우의 수를 배열로
std::list<std::list<std::string>> ListStringGenerate(
	std::string target, const std::vector<std::string>& list)
{
	std::vector<std::list<std::string>> table(target.size() + 1, std::list<std::string>());
}