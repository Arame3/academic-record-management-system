#include "StudentManager.h"
#include <iostream>


StudentManager::StudentManager()
{

}

int StudentManager::getCount() const
{
	return static_cast<int>(students.size());

}

int StudentManager::findStudentIndexByName(const std::string& name) const
{
	for (int i = 0; i < static_cast<int>(students.size()); i++) 
	{
		if (students[i].getName() == name)
		{
			return i;
		}
	}

	return -1;

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

void StudentManager::printAll() const
{
	if (students.empty())
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