#include <iostream>
#include <map>
#include <numeric>
#include "Student.h"

namespace MapPrac
{
	// 벡터 연습
	// 1.학생추가
	// 2.학생제거 (번호)
	// 3.전체 학생 출력
	// 4.평균 및 총점 출력
	// 5.평균 이상 학생 출력
	// 6.종료
	// 예외처리: 학생을 추가할 때 같은 번호를 입력하면 중복 에러 발생.

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
			std::cout << "\n다음과 같은 명령을 수행할 수 있습니다." << std::endl;
			std::cout << "1.학생추가\n" << "2.학생제거 (번호)\n" <<
				"3.전체 학생 출력\n" << "4.평균 및 총점 출력\n" <<
				"5.평균 이상 학생 출력\n" << "6.종료\n" << std::endl;
			
			std::cout << "명령 ->> ";
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
		std::cout << "번호 이름 점수를 입력하세요." << std::endl;
		int number{}, score{};
		std::string name{};
		
		if (!(std::cin >> number >> name >> score))
		{
			std::cout << "정보 입력이 잘못되었습니다." << std::endl;
		}
		
		if (map.find(number) != map.end())
		{
			std::cout << "중복된 학생 번호 입니다." << std::endl;
			return;
		}

		map.insert(std::pair<int, Student>{number, Student{ name, score }});
		std::cout << "학생이 추가되었 습니다." << std::endl;
	}

	void DeleteStudent(std::map<int, Student>& map)
	{
		int inputNum{};
		std::cout << "제거할 번호: " ;
		if (!(std::cin >> inputNum))
		{
			std::cout << "정보 입력이 잘못되었습니다." << std::endl;
		}

		if (map.find(inputNum) == map.end())
		{
			std::cout << "존재하지 않는 번호입니다." << std::endl;
		}
		else
		{
			map.erase(inputNum);
			std::cout << "해당 번호가 제거되었습니다." << std::endl;
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

		std::cout << "평균: " << (static_cast<float>(total) / map.size()) <<
			" 총점: " << total << std::endl;
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
