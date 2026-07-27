#pragma once

#include <string>

#include "InputReader.h"
#include "Student.h"


class StudentInputReader
{
private:

	InputReader& inputReader;

	static constexpr int minimumStudentId = 1;

	static constexpr double minimumScore = 0.0;

	static constexpr double maximumScore = 100.0;

public:

	explicit StudentInputReader
	(
		InputReader& inputReader
	);

	StudentInputReader
	(
		const StudentInputReader& other
	) = delete;

	StudentInputReader& operator=
		(
			const StudentInputReader& other
			) = delete;

	int readStudentId() const;

	std::string readStudentName() const;

	double readStudentScore() const;

	Student readStudent() const;

};