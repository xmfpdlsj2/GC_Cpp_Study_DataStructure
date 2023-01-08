
#include <iostream>
#include <vector>
#include "Student.h"

void VectorPractice();
void InputStage(std::vector<Student>& vec);
void AddStudent(std::vector<Student>& vec);


int main()
{
	VectorPractice();
}

// 벡터 연습
// 1.학생추가
// 2.학생제거 (번호)
// 3.전체 학생 출력
// 4.평균 및 총점 출력
// 5.평균 이상 학생 출력
// 6.종료
// 예외처리: 학생을 추가할 때 같은 번호를 입력하면 중복 에러 발생.

void VectorPractice()
{
	Student std{ 1, "Kim", 80 };
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
	std::cout << "\n다음과 같은 명령을 수행할 수 있습니다." << std::endl;
	std::cout << "1.학생추가\n" << "2.학생제거 (번호)\n" <<
		"3.전체 학생 출력\n" << "4.평균 및 총점 출력\n" <<
		"5.평균 이상 학생 출력\n" << "6.종료\n" << std::endl;

	int input{};
	std::cout << "명령 ->> ";
	while (std::cin >> input)
	{
		switch (input)
		{
			case 1:
				AddStudent(vec);
				break;

			case 2:
				break;

			case 3:
				for (auto& student : vec)
				{
					student.Print();
				}
				break;

			case 4:
				break;

			case 5:
				break;

			case 6:
				break;

			default:
				break;
		}
		std::cout << "\n명령 ->> ";
	}
}
void AddStudent(std::vector<Student>& vec)
{
	std::cout << "	학생을 추가합니다. 정보를 입력해주세요" << std::endl;

	std::cout << "번호: ";
	int number{};
	if (!(std::cin >> number))
	{
		std::cout << "정보를 잘못 입력했습니다!" << std::endl;
		return;
	}

	std::cout << "이름: ";
	std::string name{};
	if (!(std::cin >> name))
	{
		std::cout << "정보를 잘못 입력했습니다!" << std::endl;
		return;
	}

	int score{};
	std::cout << "점수: ";
	if (!(std::cin >> score))
	{
		std::cout << "정보를 잘못 입력했습니다!" << std::endl;
		return;
	}
	
	for (auto& student : vec)
	{
		if (student.GetNumber() == number)
		{
			std::cout << "에러! 번호가 중복됩니다!" << std::endl;
			return;
		}
	}
	
	vec.push_back(Student{ number, name, score });
	std::cout << "학생이 추가되었습니다." << std::endl;
}