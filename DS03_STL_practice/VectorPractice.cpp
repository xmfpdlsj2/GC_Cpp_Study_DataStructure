#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include "Student.h"

namespace VectorPrac
{
	// ���� ����
	// 1.�л��߰�
	// 2.�л����� (��ȣ)
	// 3.��ü �л� ���
	// 4.��� �� ���� ���
	// 5.��� �̻� �л� ���
	// 6.����
	// ����ó��: �л��� �߰��� �� ���� ��ȣ�� �Է��ϸ� �ߺ� ���� �߻�.

	void VectorPractice()
	{
		std::vector<Student> vec{};
		vec.push_back(Student{ 1, "Kim", 80 });
		vec.push_back(Student{ 2, "Lee", 20 });
		vec.push_back(Student{ 3, "Park", 50 });
		vec.push_back(Student{ 4, "Choi", 30 });


		for (auto& student : vec)
		{
			student.Print();
		}

		InputStage(vec);
	}

	void InputStage(std::vector<Student>& vec)
	{
		std::cout << "\n������ ���� ����� ������ �� �ֽ��ϴ�." << std::endl;
		std::cout << "1.�л��߰�\n" << "2.�л����� (��ȣ)\n" <<
			"3.��ü �л� ���\n" << "4.��� �� ���� ���\n" <<
			"5.��� �̻� �л� ���\n" << "6.����\n" << std::endl;

		int input{};
		std::cout << "��� ->> ";
		while (std::cin >> input)
		{
			switch (input)
			{
				case 1:
					AddStudent(vec);
					break;

				case 2:
					DeleteStudent(vec);
					break;

				case 3:
					for (auto& student : vec)
					{
						student.Print();
					}
					break;

				case 4:
					PrintAverageNScore(vec);
					break;

				case 5:
					PrintUpperAverage(vec);
					break;

				case 6:
					return;
				default:
					return;
					break;
			}
			std::cout << "\n��� ->> ";
		}
	}
	void AddStudent(std::vector<Student>& vec)
	{
		std::cout << "	�л��� �߰��մϴ�. ������ �Է����ּ���" << std::endl;

		std::cout << "��ȣ: ";
		int number{};
		if (!(std::cin >> number))
		{
			std::cout << "������ �߸� �Է��߽��ϴ�!" << std::endl;
			return;
		}

		std::cout << "�̸�: ";
		std::string name{};
		if (!(std::cin >> name))
		{
			std::cout << "������ �߸� �Է��߽��ϴ�!" << std::endl;
			return;
		}

		int score{};
		std::cout << "����: ";
		if (!(std::cin >> score))
		{
			std::cout << "������ �߸� �Է��߽��ϴ�!" << std::endl;
			return;
		}

		for (auto& student : vec)
		{
			if (student.GetNumber() == number)
			{
				std::cout << "����! ��ȣ�� �ߺ��˴ϴ�!" << std::endl;
				return;
			}
		}
		//// �˰��� ������	
		//auto itr = std::find_if(vec.begin(), vec.end(), [&](auto& elem) -> bool
		//	{
		//		return elem.GetNumber() == number;
		//	});

		vec.push_back(Student{ number, name, score });
		std::cout << "�л��� �߰��Ǿ����ϴ�." << std::endl;
	}

	void DeleteStudent(std::vector<Student>& vec)
	{
		int number{};
		std::cout << "������ �л� ��ȣ: ";
		if (!(std::cin >> number))
		{
			std::cout << "�߸� �Է��߽��ϴ�!" << std::endl;
			return;
		}

		for (std::vector<Student>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		{
			if ((*itr).GetNumber() == number)
			{
				vec.erase(itr);
				std::cout << number << "�� �л��� �����߽��ϴ�." << std::endl;
				return;
			}
		}
		//// �˰��� ������	
		//vec.erase(std::remove_if(vec.begin(), vec.end(), [&](auto& elem) -> bool
		//	{
		//		return elem.GetNumber() == number;
		//	}));

		std::cout << "���� ��ȣ �Դϴ�!" << std::endl;
	}

	void PrintAverageNScore(std::vector<Student>& vec)
	{
		int total{};
		for (auto& student : vec)
		{
			total += student.GetScore();
		}
		//// �˰��� ������
		//total = std::accumulate(vec.begin(), vec.end(), 0, [](int accum, auto& elem) -> int
		//	{
		//		return accum += elem.GetScore();
		//	});

		std::cout << "���: " << (static_cast<float>(total) / vec.size()) <<
			" ����: " << total << std::endl;
	}

	void PrintUpperAverage(std::vector<Student>& vec)
	{
		int total{};
		for (auto& student : vec)
		{
			total += student.GetScore();
		}
		float average{ (static_cast<float>(total) / vec.size()) };

		for (auto& student : vec)
		{
			if (student.GetScore() >= average)
			{
				student.Print();
			}
		}
		//// �˰��� ������
		//std::for_each(vec.begin(), vec.end(), [&](Student& elem)
		//	{
		//		if (elem.GetScore() >= average)
		//		{
		//			elem.Print();
		//		}
		//	});
	}
}