#include "StudentManager.h"
#include <iostream>


StudentManager::StudentManager()
{

}

int StudentManager::getCount() const
{
	return static_cast<int>(students.size());

}

bool StudentManager::isEmpty() const
{
	return students.empty();

}

double StudentManager::getAverageScore() const
{
	if (isEmpty())
	{
		return 0.0;
	}

	double sum = 0.0;
	int count = static_cast<int>(students.size());

	for (int i = 0; i < count; i++)
	{
		sum += students[i].getScore();
	}

	return sum / count;

}



int StudentManager::findStudentIndexByName(const std::string& name) const
{
	int count = static_cast<int>(students.size());

	for (int i = 0; i < count; i++) 
	{
		if (students[i].getName() == name)
		{
			return i;
		}
	}

	return -1;

}

int StudentManager::findBestStudentIndex() const
{
	if (isEmpty())
	{
		return -1;
	}

	int bestIndex = 0;

	for (int i = 1; i < static_cast<int>(students.size()); i++)
	{
		if (students[i].getScore() > students[bestIndex].getScore())
		{
			bestIndex = i;
		}
	}

	return bestIndex;

}

void StudentManager::addStudent(const Student& student)
{
	students.push_back(student);

}

bool StudentManager::removeStudentByName(const std::string& name)
{
	int index = findStudentIndexByName(name);

	if (index == -1)
	{
		return false;
	}

	students.erase(students.begin() + index);

	return true;

}

bool StudentManager::updateStudentScore(const std::string& name, double newScore)
{
	int index = findStudentIndexByName(name);

	if (index == -1)
	{
		return false;
	}

	students[index].setScore(newScore);

	return true;

}

void StudentManager::printAll() const
{
	if (isEmpty())
	{
		std::cout << "No students found."
			<< std::endl;

	}

	else
	{
		for (int i = 0; i < static_cast<int>(students.size()); i++)
		{
			std::cout << students[i]
				<< std::endl;
		}
	}

}