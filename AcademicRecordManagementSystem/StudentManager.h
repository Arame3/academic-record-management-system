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

	bool isScoreValid(double score) const;

	double getAverageScore() const;

	int getPassedStudentCount(double passingScore) const;

	int getFailedStudentCount(double passingScore) const;

	double getHighestScore() const;

	double getLowestScore() const;

	double getPassRate(double passingScore) const;

	int getExcellentStudentCount(double excellentScore) const;

	int getAtRiskStudentCount(double passingScore) const;



	int findStudentIndexById(int id) const;

	bool hasStudentById(int id) const;

	int findStudentIndexByName(const std::string& name) const;

	int findBestStudentIndex() const;



	bool addStudent(const Student& student);

	bool removeStudentById(int id);

	bool removeStudentByName(const std::string& name);

	bool updateStudentScoreById(int id, double newScore);

	bool updateStudentScore(const std::string& name, double newScore);

	bool updateStudentNameById(int id, const std::string& newName);



	void printStudentById(int id) const;

	void printBestStudent() const;

	void printStudentCount() const;

	void printPassedStudents(double passingScore) const;

	void printFailedStudents(double passingScore) const;

	void printAllStudentsWithHeader() const;

	void printExcellentStudents(double excellentScore) const;

	void printAtRiskStudents(double passingScore) const;

	void printStatistics(double passingScore) const;

	void printAcademicReport(double passingScore, double excellentScore) const;

	void printAll() const;

};