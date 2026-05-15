#pragma once

#include "Student.h"
#include <vector>
#include <string>


class StudentManager
{
private:

	std::vector<Student> students;

public:

	StudentManager();


	int getCount() const;

	bool isEmpty() const;

	double getAverageScore() const;

	int findStudentIndexByName(const std::string& name) const;

	int findBestStudentIndex() const;

	void addStudent(const Student& student);

	bool removeStudentByName(const std::string& name);

	bool updateStudentScore(const std::string& name, double newScore);


	void printBestStudent() const;

	void printAll() const;

};