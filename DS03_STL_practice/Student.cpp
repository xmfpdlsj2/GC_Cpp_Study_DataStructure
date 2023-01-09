#include "Student.h"

Student::Student(int number, std::string name, int score)
	: mNumber{ number }, mName{ name }, mScore{ score }
{
}

Student::~Student()
{
}

void Student::Print() const 
{
	std::cout << "(" << mNumber << ") " <<
		mName << " : " << mScore << std::endl;
}

const int& Student::GetNumber() const
{
	return mNumber;
}

const int& Student::GetScore() const
{
	return mScore;
}
