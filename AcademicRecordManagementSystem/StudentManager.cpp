#include "StudentManager.h"
#include <iostream>


StudentManager::StudentManager()
{

}

int StudentManager::getCount() const
{
	return static_cast<int>(students.size());

}

void StudentManager::addStudent(const Student& student)
{
	students.push_back(student);

}

void StudentManager::printAll() const
{
	if (students.empty())
	{
		std::cout << "No Students found."
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