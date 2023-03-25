#pragma once
#include <vector>

// �Ǻ���ġ 
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
// m x n�� �������� �»��->���ϴ����� �̵��ϴ� ��� ����Ǽ�
// �̵��� �������̳� �Ʒ������θ� ���� �ֽ��ϴ�.
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

// ������ �迭 nums���� ���ڵ��� �����Ͽ� sum�� ����� �� �� �ִ��� Ȯ���ϴ� �Լ�
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

// ������ �迭 nums���� ���ڵ��� �����Ͽ� sum�� ����� �� �� �ִ��� Ȯ���ϴ� �Լ�
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
					// ��������ڷ� ���� �������
					table[i + e] = std::make_shared<std::vector<int>>(*table[i]);
					table[i + e]->push_back(e);
				}
			}
		}
	}
	return table[sum];
}

// ������ �迭 nums���� ���ڵ��� �����Ͽ� sum�� ����� �� �� �ִ� ���� ���յ� 
// �߿� ���Ұ� ���� ���� ���
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
				// �迭 �ε��� ���� : ��������
				// ������ ������ ����
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

// ���ڿ� ����--------------------------------------------------------------------- 
// �־��� ���ڿ��� ���� stringList���� target ���ڿ��� ���� �� �ִ°�?
// target�� ����� ���� ������ ���Ҹ� ������ ����ص� �˴ϴ�. 
// target�� �� ���ڿ��̸� ��.
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

// �־��� ���ڿ��� ���� stringList���� target ���ڿ��� ���� �� �ִ� ��� ����� �� ��ȯ
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
// �־��� ���ڿ��� ���� stringList���� target ���ڿ��� ���� �� �ִ� ��� ����� ���� �迭��
std::list<std::list<std::string>> ListStringGenerate(
	std::string target, const std::vector<std::string>& list)
{
	std::vector<std::list<std::string>> table(target.size() + 1, std::list<std::string>());
}