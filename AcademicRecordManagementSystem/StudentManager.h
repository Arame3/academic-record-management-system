#pragma once

#include <vector>
#include <string>

#include "Student.h"

class StudentManager
{
private:

	std::vector<Student> students;

public:

	StudentManager();


	int getCount() const;

	bool isEmpty() const;

	double getAverageScore() const;


	int findStudentIndexById(int id) const;

	bool hasStudentById(int id) const;

	int findStudentIndexByName(const std::string& name) const;

	int findBestStudentIndex() const;


	bool addStudent(const Student& student);

	bool removeStudentById(int id);

	bool removeStudentByName(const std::string& name);

	bool updateStudentScoreById(int id, double newScore);

	bool updateStudentScore(const std::string& name, double newScore);


	void printStudentById(int id) const;

	void printBestStudent() const;

	void printStudentCount() const;

	void printAllStudentsWithHeader() const;

	void printStatistics() const;

	void printAll() const;

};