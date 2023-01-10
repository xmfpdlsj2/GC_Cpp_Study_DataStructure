#include "Student.h"

using namespace VectorPrac;
//{
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
//}
namespace MapPrac
{
	Student::Student(std::string name, int score)
		:mName{ name }, mScore{ score }
	{
	}

	Student::~Student()
	{
	}

	void Student::Print() const
	{
		std::cout << mName << " : " << mScore << std::endl;
	}

	const int& Student::GetScore() const
	{
		return mScore;
	}
}