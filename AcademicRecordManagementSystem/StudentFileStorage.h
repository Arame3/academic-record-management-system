#pragma once

#include <string>

#include <vector>

#include "Student.h"
#include "StudentFileLoadResult.h"

class StudentFileStorage
{
private:

    static bool tryParseStudentLine(const std::string& line, Student& student);

public:

    static bool saveToCsv(const std::string& filePath, const std::vector<Student>& students);

    static StudentFileLoadResult loadFromCsv
    (
        const std::string& filePath
    );

};