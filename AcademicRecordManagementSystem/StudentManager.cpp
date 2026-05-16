#include <iostream>

#include "StudentManager.h"



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



int StudentManager::findStudentIndexById(int id) const
{
	int count = static_cast<int>(students.size());

	for (int i = 0; i < count; i++)
	{
		if (students[i].getId() == id)
		{
			return i;
		}
	}

	return -1;

}

bool StudentManager::hasStudentById(int id) const
{
	return findStudentIndexById(id) != -1;

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



bool StudentManager::addStudent(const Student& student)
{
	if (student.getId() == 0)
	{
		return false;
	}

	if (hasStudentById(student.getId()))
	{
		return false;
	}

	students.push_back(student);

	return true;

}

bool StudentManager::removeStudentById(int id)
{
	int index = findStudentIndexById(id);

	if (index == -1)
	{
		return false;
	}

	students.erase(students.begin() + index);

	return true;

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

bool StudentManager::updateStudentScoreById(int id, double newScore) 
{
	int index = findStudentIndexById(id);

	if (index == -1)
	{
		return false;
	}

	students[index].setScore(newScore);

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



void StudentManager::printStudentById(int id) const
{
	int index = findStudentIndexById(id);

	if (index == -1)
	{
		std::cout << "Student with ID "
			<< id
			<< " was not found."
			<< std::endl;

		return;
	}

	std::cout << "Student found: "
		<< students[index]
		<< std::endl;
}

void StudentManager::printBestStudent() const
{
	int bestIndex = findBestStudentIndex();

	if (bestIndex == -1)
	{
		std::cout << "No students available to determine the best student."
			<< std::endl;

		return;
	}

	std::cout << "Best student: "
		<< students[bestIndex]
		<< std::endl;

}

void StudentManager::printStudentCount() const
{
	std::cout << "Student count: "
		<< getCount()
		<< std::endl;

}

void StudentManager::printAllStudentsWithHeader() const
{
	printStudentCount();

	printAll();

}

void StudentManager::printStatistics() const
{
	if (isEmpty())
	{
		std::cout << "No statistics available. The student list is empty."
			<< std::endl;

		return;
	}

	std::cout << "Student count: "
		<< getCount()
		<< std::endl;

	std::cout << "Average score: "
		<< getAverageScore()
		<< std::endl;

	printBestStudent();

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