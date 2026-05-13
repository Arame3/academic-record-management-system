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

	int findStudentIndexByName(const std::string& name) const;

	void addStudent(const Student& student);

	bool removeStudentByName(const std::string& name);

	void printAll() const;

};