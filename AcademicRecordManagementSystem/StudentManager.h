#pragma once

#include "Student.h"
#include <vector>


class StudentManager
{
private:

	std::vector<Student> students;

public:

	StudentManager();

	int getCount() const;

	void addStudent(const Student& student);

	void printAll() const;

};