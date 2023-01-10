#pragma once
#include <iostream>
#include <vector>
#include <map>

namespace VectorPrac
{
	class Student
	{
	private:
		int mNumber;
		std::string mName;
		int mScore;

	public:
		Student(int number, std::string name, int score);
		~Student();
		void Print() const;
		const int& GetNumber() const;
		const int& GetScore() const;
	};

	void VectorPractice();

	void InputStage(std::vector<Student>& vec);
	void AddStudent(std::vector<Student>& vec);
	void DeleteStudent(std::vector<Student>& vec);
	void PrintAverageNScore(std::vector<Student>& vec);
	void PrintUpperAverage(std::vector<Student>& vec);
}
namespace MapPrac
{
	class Student
	{
	private:
		std::string mName;
		int mScore;

	public:
		Student(std::string name, int score);
		~Student();
		void Print() const;
		const int& GetScore() const;
	};

	void MapPractice();

	void InputStage(std::map<int, Student>& map);
	void AddStudent(std::map<int, Student>& map);
	void DeleteStudent(std::map<int, Student>& map);
	void PrintAllStudents(std::map<int, Student>& map);
	void PrintAverageNScore(std::map<int, Student>& map);
	void PrintUpperAverage(std::map<int, Student>& map);
}

