#include <iostream>
#include <map>
#include <numeric>
#include "Student.h"

namespace MapPrac
{
	// ���� ����
	// 1.�л��߰�
	// 2.�л����� (��ȣ)
	// 3.��ü �л� ���
	// 4.��� �� ���� ���
	// 5.��� �̻� �л� ���
	// 6.����
	// ����ó��: �л��� �߰��� �� ���� ��ȣ�� �Է��ϸ� �ߺ� ���� �߻�.

	void MapPractice()
	{
		std::map<int, Student> map{};
		map.insert(std::pair<int, Student>{1, Student{"Kim", 80 }});
		map.insert(std::pair<int, Student>{2, Student{"Lee", 20 }});
		map.insert(std::pair<int, Student>{3, Student{"Park", 50 }});
		map.insert(std::pair<int, Student>{4, Student{"Choi", 30 }});
		PrintAllStudents(map);

		InputStage(map);
	}


	void InputStage(std::map<int, Student>& map)
	{
		bool isWorking{ true };
		int input{};
		while (isWorking)
		{
			std::cout << "\n������ ���� ����� ������ �� �ֽ��ϴ�." << std::endl;
			std::cout << "1.�л��߰�\n" << "2.�л����� (��ȣ)\n" <<
				"3.��ü �л� ���\n" << "4.��� �� ���� ���\n" <<
				"5.��� �̻� �л� ���\n" << "6.����\n" << std::endl;
			
			std::cout << "��� ->> ";
			if (!(std::cin >> input))
			{
				return;
			}
			switch (input)
			{
				case 1:
					AddStudent(map);
					break;

				case 2:
					DeleteStudent(map);
					break;

				case 3:
					PrintAllStudents(map);
					break;

				case 4:
					PrintAverageNScore(map);
					break;

				case 5:
					PrintUpperAverage(map);
					break;

				case 6:
					isWorking = false;
				default:
					break;
			}
		}
	}

	void AddStudent(std::map<int, Student>& map)
	{
		std::cout << "��ȣ �̸� ������ �Է��ϼ���." << std::endl;
		int number{}, score{};
		std::string name{};
		
		if (!(std::cin >> number >> name >> score))
		{
			std::cout << "���� �Է��� �߸��Ǿ����ϴ�." << std::endl;
		}
		
		if (map.find(number) != map.end())
		{
			std::cout << "�ߺ��� �л� ��ȣ �Դϴ�." << std::endl;
			return;
		}

		map.insert(std::pair<int, Student>{number, Student{ name, score }});
		std::cout << "�л��� �߰��Ǿ� ���ϴ�." << std::endl;
	}

	void DeleteStudent(std::map<int, Student>& map)
	{
		int inputNum{};
		std::cout << "������ ��ȣ: " ;
		if (!(std::cin >> inputNum))
		{
			std::cout << "���� �Է��� �߸��Ǿ����ϴ�." << std::endl;
		}

		if (map.find(inputNum) == map.end())
		{
			std::cout << "�������� �ʴ� ��ȣ�Դϴ�." << std::endl;
		}
		else
		{
			map.erase(inputNum);
			std::cout << "�ش� ��ȣ�� ���ŵǾ����ϴ�." << std::endl;
		}
	}

	void PrintStudent(std::map<int, Student>::value_type& pair)
	{
		std::cout << "(" << pair.first << ") ";
		pair.second.Print();
	}

	void PrintAllStudents(std::map<int, Student>& map)
	{
		for (auto& student : map)
		{
			PrintStudent(student);
		}
	}

	void PrintAverageNScore(std::map<int, Student>& map)
	{
		int total{};
		total = std::accumulate(map.begin(), map.end(), 0, [&](int accum, auto& student)->int
			{
				return accum += student.second.GetScore();
			});

		std::cout << "���: " << (static_cast<float>(total) / map.size()) <<
			" ����: " << total << std::endl;
	}

	void PrintUpperAverage(std::map<int, Student>& map)
	{
		float average{};
		average = std::accumulate(map.begin(), map.end(), 0, [&](int accum, auto& student)->int
			{
				return accum += student.second.GetScore();
			});
		average /= map.size();

		for (auto& student : map)
		{
			if (student.second.GetScore() >= average)
			{
				PrintStudent(student);
			}
		}
	}
}
