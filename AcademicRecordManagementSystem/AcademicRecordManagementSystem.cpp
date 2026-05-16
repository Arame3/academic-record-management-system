#include <iostream>
#include <string>

#include "Student.h"
#include "StudentManager.h"



static void printSectionTitle(const std::string& title)
{
    std::cout << "\n============================================================" << std::endl;
    std::cout << "                    " << title << std::endl;
    std::cout << "============================================================" << std::endl;
}



void addStudentAndPrintResult(StudentManager& manager, const Student& student)
{
    if (manager.addStudent(student))
    {
        std::cout << "Student added successfully: "
            << student.getName()
            << " (ID: "
            << student.getId()
            << ")"
            << std::endl;
    }
    else
    {
        std::cout << "Could not add student: "
            << student.getName()
            << ". Invalid or duplicate ID."
            << std::endl;
    }
}



void updateStudentScoreAndPrintResult(StudentManager& manager, int id, double newScore)
{
    if (manager.updateStudentScoreById(id, newScore))
    {
        std::cout << "Successfully updated score for student ID "
            << id
            << "."
            << std::endl;
    }
    else
    {
        std::cout << "Could not update student ID "
            << id
            << ". Student not found."
            << std::endl;
    }
}



void removeStudentAndPrintResult(StudentManager& manager, int id)
{
    if (manager.removeStudentById(id))
    {
        std::cout << "Successfully removed student with ID "
            << id
            << "."
            << std::endl;
    }
    else
    {
        std::cout << "Could not remove student with ID "
            << id
            << ". Student not found."
            << std::endl;
    }
}



int main()
{
    printSectionTitle("Academic Record Management System");


    StudentManager manager;


    printSectionTitle("Initial Student List");
    manager.printAllStudentsWithHeader();



    printSectionTitle("Adding Students");

    addStudentAndPrintResult(manager, Student(1, "Ani", 95.5));

    addStudentAndPrintResult(manager, Student(2, "Aram", 150.0));
    std::cout << "Warning: Invalid score for Aram was converted to 0." << std::endl;

    addStudentAndPrintResult(manager, Student(3, "Mane", 88.5));

    addStudentAndPrintResult(manager, Student(4, "", 77.0));
    std::cout << "Note: Empty student name was converted to Unknown." << std::endl;

    addStudentAndPrintResult(manager, Student(0, "Invalid ID Student", 80.0));

    addStudentAndPrintResult(manager, Student(1, "Duplicate Ani", 70.0));



    printSectionTitle("Current Students");

    manager.printAllStudentsWithHeader();

    printSectionTitle("Searching Students");

    manager.printStudentById(1);

    manager.printStudentById(999);

    printSectionTitle("Updating Student Scores");

    updateStudentScoreAndPrintResult(manager, 3, 99.0);

    updateStudentScoreAndPrintResult(manager, 999, 90.0);

    updateStudentScoreAndPrintResult(manager, 2, 150.0);
    std::cout << "Note: Invalid score for student ID 2 was converted to 0." << std::endl;


    printSectionTitle("Students After Updates");
    manager.printAllStudentsWithHeader();

    double passingScore = 50.0;

    printSectionTitle("Statistics");
    manager.printStatistics(passingScore);

    printSectionTitle("Passed Students");
    manager.printPassedStudents(passingScore);

    printSectionTitle("Failed Students");
    manager.printFailedStudents(passingScore);

    printSectionTitle("Removing Students");

    removeStudentAndPrintResult(manager, 1);

    removeStudentAndPrintResult(manager, 999);

    printSectionTitle("Final Student List");
    manager.printAllStudentsWithHeader();

    std::cout << "\nProgram finished successfully." << std::endl;

    return 0;

}