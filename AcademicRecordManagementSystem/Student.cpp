#include "Student.h"



Student::Student()
	: id(0), name("Unknown"), score(0.0)
{

}

Student::Student(int id, const std::string& name, double score)
	: id(0), name("Unknown"), score(0.0)
{
	setId(id);

	setName(name);

	setScore(score);

}



int Student::getId() const
{
	return id;

}

std::string Student::getName() const
{
	return name;

}

double Student::getScore() const
{
	return score;

}



void Student::setId(int id)
{
	if (id > 0)
	{
		this->id = id;
	}
	else
	{
		this->id = 0;
	}

}

void Student::setName(const std::string& name)
{
	if (name.empty())
	{
		this->name = "Unknown";
	}
	else
	{
		this->name = name;
	}

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
	out << "Student{ID: " << student.id
		<< ", Name: " << student.name
		<< ", Score: " << student.score
		<< "}";

	return out;

}