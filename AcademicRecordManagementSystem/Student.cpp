#include "Student.h"



Student::Student()
	: name("Unknown"), score(0.0)
{

}

Student::Student(const std::string& name, double score)
	: name(name), score(0.0)
{
	setScore(score);

}



std::string Student::getName()
	const
{
	return name;

}

double Student::getScore()
	const
{
	return score;

}

void Student::setName(const std::string& name)
{
	this->name = name;

}

void Student::setScore(double score)
{
	if (score >= 0.0 && score <= 100.0)
	{
		this->score = score;
	}
	else
	{
		this->score = 0.0;
	}

}



std::ostream& operator<<(std::ostream& out, const Student& student)
{
	out << "Student{Name: " << student.name
		<< ", Score: " << student.score
		<< "}";

	return out;

}