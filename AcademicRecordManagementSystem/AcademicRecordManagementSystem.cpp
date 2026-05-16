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

    if (manager.updateStudentScoreById(3, 99.0))
    {
        std::cout << "Successfully updated score for student ID 3." << std::endl;
    }
    else
    {
        std::cout << "Could not update student ID 3. Student not found." << std::endl;
    }

    if (manager.updateStudentScoreById(999, 90.0))
    {
        std::cout << "Successfully updated score for student ID 999." << std::endl;
    }
    else
    {
        std::cout << "Could not update student ID 999. Student not found." << std::endl;
    }

    if (manager.updateStudentScoreById(2, 150.0))
    {
        std::cout << "Updated score for student ID 2, but invalid score was converted to 0." << std::endl;
    }
    else
    {
        std::cout << "Could not update student ID 2. Student not found." << std::endl;
    }

    printSectionTitle("Students After Updates");
    manager.printAllStudentsWithHeader();

    printSectionTitle("Statistics");
    manager.printStatistics();

    printSectionTitle("Removing Students");

    if (manager.removeStudentById(1))
    {
        std::cout << "Successfully removed student with ID 1." << std::endl;
    }
    else
    {
        std::cout << "Could not remove student with ID 1. Student not found." << std::endl;
    }

    if (manager.removeStudentById(999))
    {
        std::cout << "Successfully removed student with ID 999." << std::endl;
    }
    else
    {
        std::cout << "Could not remove student with ID 999. Student not found." << std::endl;
    }

    printSectionTitle("Final Student List");
    manager.printAllStudentsWithHeader();

    std::cout << "\nProgram finished successfully." << std::endl;

    return 0;

}