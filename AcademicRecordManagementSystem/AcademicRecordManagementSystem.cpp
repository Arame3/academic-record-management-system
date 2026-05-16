#include <iostream>
#include <string>

#include "Student.h"
#include "StudentManager.h"


void printSectionTitle(const std::string& title)
{
    std::cout << "\n========================================================================================================================" << std::endl;
    std::cout << "   " << title << std::endl;
    std::cout << "========================================================================================================================" << std::endl;

}


int main()
{
    printSectionTitle("Academic Record Management System");

    StudentManager manager;

    printSectionTitle("Initial Student List");
    manager.printAll();

    printSectionTitle("Adding Students");

    manager.addStudent(Student("Ani", 95.5));
    std::cout << "Student added successfully: Ani" << std::endl;

    manager.addStudent(Student("Aram", 150.0));
    std::cout << "Student added successfully: Aram" << std::endl;
    std::cout << "Warning: Invalid score for Aram was converted to 0." << std::endl;

    manager.addStudent(Student("Mane", 88.5));
    std::cout << "Student added successfully: Mane" << std::endl;

    printSectionTitle("Current Students");

    std::cout << "Current student count: "
        << manager.getCount()
        << std::endl;

    manager.printAll();

    printSectionTitle("Searching Students");

    int aniIndex = manager.findStudentIndexByName("Ani");

    if (aniIndex != -1)
    {
        std::cout << "Ani found at index: " << aniIndex << std::endl;
    }
    else
    {
        std::cout << "Ani was not found." << std::endl;
    }

    int davidIndex = manager.findStudentIndexByName("David");

    if (davidIndex != -1)
    {
        std::cout << "David found at index: " << davidIndex << std::endl;
    }
    else
    {
        std::cout << "David was not found." << std::endl;
    }

    printSectionTitle("Updating Student Scores");

    if (manager.updateStudentScore("Mane", 99.0))
    {
        std::cout << "Successfully updated Mane's score." << std::endl;
    }
    else
    {
        std::cout << "Could not update Mane. Student not found." << std::endl;
    }

    if (manager.updateStudentScore("David", 90.0))
    {
        std::cout << "Successfully updated David's score." << std::endl;
    }
    else
    {
        std::cout << "Could not update David. Student not found." << std::endl;
    }

    if (manager.updateStudentScore("Aram", 150.0))
    {
        std::cout << "Updated Aram's score, but invalid score was converted to 0." << std::endl;
    }
    else
    {
        std::cout << "Could not update Aram. Student not found." << std::endl;
    }

    printSectionTitle("Students After Updates");
    manager.printAll();

    printSectionTitle("Statistics");

    manager.printStatistics();

    std::cout << "Best student index: "
        << manager.findBestStudentIndex()
        << std::endl;

    printSectionTitle("Removing Students");

    if (manager.removeStudentByName("Ani"))
    {
        std::cout << "Successfully removed student: Ani" << std::endl;
    }
    else
    {
        std::cout << "Could not remove Ani. Student not found." << std::endl;
    }

    if (manager.removeStudentByName("David"))
    {
        std::cout << "Successfully removed student: David" << std::endl;
    }
    else
    {
        std::cout << "Could not remove David. Student not found." << std::endl;
    }

    std::cout << "Student count after removal: "
        << manager.getCount()
        << std::endl;

    printSectionTitle("Final Student List");
    manager.printAll();

    std::cout << "\nProgram finished successfully." << std::endl;


    return 0;

}