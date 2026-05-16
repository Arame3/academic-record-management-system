#include <iostream>
#include <string>

#include "Student.h"
#include "StudentManager.h"


static void printSectionTitle(const std::string& title)
{
    std::cout << "\n========================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "========================================" << std::endl;
}


int main()
{
    printSectionTitle("Academic Record Management System");

    StudentManager manager;

    printSectionTitle("Initial Student List");
    manager.printAll();

    printSectionTitle("Adding Students");

    if (manager.addStudent(Student(1, "Ani", 95.5)))
    {
        std::cout << "Student added successfully: Ani" << std::endl;
    }
    else
    {
        std::cout << "Could not add Ani. Invalid or duplicate ID." << std::endl;
    }

    if (manager.addStudent(Student(2, "Aram", 150.0)))
    {
        std::cout << "Student added successfully: Aram" << std::endl;
        std::cout << "Warning: Invalid score for Aram was converted to 0." << std::endl;
    }
    else
    {
        std::cout << "Could not add Aram. Invalid or duplicate ID." << std::endl;
    }

    if (manager.addStudent(Student(3, "Mane", 88.5)))
    {
        std::cout << "Student added successfully: Mane" << std::endl;
    }
    else
    {
        std::cout << "Could not add Mane. Invalid or duplicate ID." << std::endl;
    }

    if (manager.addStudent(Student(1, "Duplicate Ani", 70.0)))
    {
        std::cout << "Student added successfully: Duplicate Ani" << std::endl;
    }
    else
    {
        std::cout << "Could not add Duplicate Ani. Invalid or duplicate ID." << std::endl;
    }

    printSectionTitle("Current Students");

    std::cout << "Current student count: "
        << manager.getCount()
        << std::endl;

    manager.printAll();

    printSectionTitle("Searching Students");

    int aniIndex = manager.findStudentIndexById(1);

    if (aniIndex != -1)
    {
        std::cout << "Student with ID 1 found at index: " << aniIndex << std::endl;
    }
    else
    {
        std::cout << "Student with ID 1 was not found." << std::endl;
    }

    int missingIndex = manager.findStudentIndexById(999);

    if (missingIndex != -1)
    {
        std::cout << "Student with ID 999 found at index: " << missingIndex << std::endl;
    }
    else
    {
        std::cout << "Student with ID 999 was not found." << std::endl;
    }

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
    manager.printAll();

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

    std::cout << "Student count after removal: "
        << manager.getCount()
        << std::endl;

    printSectionTitle("Final Student List");
    manager.printAll();

    std::cout << "\nProgram finished successfully." << std::endl;

    return 0;

}