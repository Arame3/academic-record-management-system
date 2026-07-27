#include "StudentInputReader.h"

#include <limits>


StudentInputReader::StudentInputReader
(
	InputReader& inputReader

)
	: inputReader(inputReader)
{

}


int StudentInputReader::readStudentId() const
{
	return inputReader.readNumber<int>
		(
			"Enter student ID: ",

			minimumStudentId,

			std::numeric_limits<int>::max()
		);

}


std::string StudentInputReader::readStudentName() const
{
	return inputReader.readNonEmptyLine
	(
		"Enter student name: "

	);

}


double StudentInputReader::readStudentScore() const
{
	return inputReader.readNumber<double>
		(
			"Enter student score: ",

			minimumScore,

			maximumScore
		);

}


Student StudentInputReader::readStudent() const
{
	int id = readStudentId();

	std::string name = readStudentName();

	double score = readStudentScore();

	return Student
	(
		id,

		name,

		score
	);

}