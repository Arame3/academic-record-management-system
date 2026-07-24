#include "StudentFileStorage.h"

#include <fstream>

#include <sstream>

bool StudentFileStorage::saveToCsv(const std::string& filePath, const std::vector<Student>& students)
{
    std::ofstream outputFile(filePath);

    if (!outputFile.is_open())
    {
        return false;
    }

    outputFile << "id,name,score" << std::endl;

    for (const Student& student : students)
    {
        outputFile << student.getId()
            << ","
            << student.getName()
            << ","
            << student.getScore()
            << std::endl;
    }

    return true;
}


StudentFileLoadResult StudentFileStorage::loadFromCsv(
    const std::string& filePath
)
{
    StudentFileLoadResult result;

    std::ifstream inputFile(filePath);

    if (!inputFile.is_open())
    {
        return result;
    }

    result.fileOpened = true;

    std::string line;

    // Skip CSV header.
    std::getline(inputFile, line);

    while (std::getline(inputFile, line))
    {
        ++result.processedLineCount;

        Student student;

        if (tryParseStudentLine(line, student))
        {
            result.students.push_back(student);
            ++result.loadedCount;
        }
        else
        {
            ++result.rejectedCount;
        }
    }

    return result;
}


bool StudentFileStorage::tryParseStudentLine(const std::string& line, Student& student)
{
    std::stringstream lineStream(line);

    std::string idText;
    std::string name;
    std::string scoreText;

    if (!std::getline(lineStream, idText, ','))
    {
        return false;
    }

    if (!std::getline(lineStream, name, ','))
    {
        return false;
    }

    if (!std::getline(lineStream, scoreText, ','))
    {
        return false;
    }

    try
    {
        int id = std::stoi(idText);
        double score = std::stod(scoreText);

        student = Student(id, name, score);

        return true;
    }
    catch (...)
    {
        return false;
    }

}