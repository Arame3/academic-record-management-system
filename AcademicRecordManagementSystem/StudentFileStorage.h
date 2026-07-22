#pragma once

#include <string>

#include <vector>

#include "Student.h"

class StudentFileStorage
{
private:

    static bool tryParseStudentLine(const std::string& line, Student& student);

public:

    static bool saveToCsv(const std::string& filePath, const std::vector<Student>& students);

    static std::vector<Student> loadFromCsv(const std::string& filePath);
};