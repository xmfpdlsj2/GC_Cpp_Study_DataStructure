#pragma once
#include <iostream>

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

