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



static void printMainMenu()
{
    std::cout << "\nMain Menu" << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << "1. Add student" << std::endl;
    std::cout << "2. Show all students" << std::endl;
    std::cout << "3. Search student by ID" << std::endl;
    std::cout << "4. Update student name" << std::endl;
    std::cout << "5. Update student score" << std::endl;
    std::cout << "6. Remove student" << std::endl;
    std::cout << "7. Show academic report" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choose an option: ";

}



static int readMenuChoice()
{
    int choice = -1;

    std::cin >> choice;

    return choice;
}



static bool isValidMenuChoice(int choice)
{
    return choice >= 0 && choice <= 7;

}



static void handleMenuChoice(
    int choice,
    StudentManager& manager,
    double passingScore,
    double excellentScore
)
{
    switch (choice)
    {

    case 1:
        std::cout << "Add student selected." << std::endl;
        break;


    case 2:
        std::cout << "Showing all students..." << std::endl;
        manager.printAllStudentsWithHeader();
        break;


    case 3:
        std::cout << "Search student by ID selected." << std::endl;
        break;


    case 4:
        std::cout << "Update student name selected." << std::endl;
        break;


    case 5:
        std::cout << "Update student score selected." << std::endl;
        break;


    case 6:
        std::cout << "Remove student selected." << std::endl;
        break;


    case 7:
        std::cout << "Showing academic report..." << std::endl;
        manager.printAcademicReport(passingScore, excellentScore);
        break;


    case 0:
        std::cout << "Exit selected." << std::endl;
        break;


    default:
        std::cout << "Invalid menu option." << std::endl;
        break;
    }

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



void updateStudentNameAndPrintResult(StudentManager& manager, int id, const std::string& newName)
{
    if (manager.updateStudentNameById(id, newName))
    {
        std::cout << "Successfully updated name for student ID "
            << id
            << "."
            << std::endl;
    }
    else
    {
        std::cout << "Could not update name for student ID "
            << id
            << ". Student not found."
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
        std::cout << "Could not update score for student ID "
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



static void loadDemoData(StudentManager& manager)
{
    addStudentAndPrintResult(manager, Student(1, "Ani", 95.5));

    addStudentAndPrintResult(manager, Student(2, "Aram", 150.0));
    std::cout << "Warning: Invalid score for Aram was converted to 0." << std::endl;

    addStudentAndPrintResult(manager, Student(3, "Mane", 88.5));

    addStudentAndPrintResult(manager, Student(4, "", 77.0));
    std::cout << "Note: Empty student name was converted to Unknown." << std::endl;

    addStudentAndPrintResult(manager, Student(0, "Invalid ID Student", 80.0));

    addStudentAndPrintResult(manager, Student(1, "Duplicate Ani", 70.0));

}



int main()
{
    printSectionTitle("Academic Record Management System");

    StudentManager manager;

    double passingScore = 40.0;
    double excellentScore = 90.0;

    printMainMenu();

    int menuChoice = readMenuChoice();

    if (isValidMenuChoice(menuChoice))
    {
        std::cout << std::endl;
        handleMenuChoice(menuChoice, manager, passingScore, excellentScore);
    }
    else
    {
        std::cout << "\nInvalid menu option. Please choose a number from 0 to 7."
            << std::endl;
    }


    std::cout << std::endl
        << std::endl;

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

    printSectionTitle("Updating Student Names");

    updateStudentNameAndPrintResult(manager, 4, "Narek");

    updateStudentNameAndPrintResult(manager, 999, "Missing Student");

    updateStudentNameAndPrintResult(manager, 3, "");
    std::cout << "Note: Empty name for student ID 3 was converted to Unknown." << std::endl;

    printSectionTitle("Students After Name Updates");
    manager.printAllStudentsWithHeader();

    printSectionTitle("Updating Student Scores");

    updateStudentScoreAndPrintResult(manager, 3, 99.0);

    updateStudentScoreAndPrintResult(manager, 999, 90.0);

    updateStudentScoreAndPrintResult(manager, 2, 150.0);
    std::cout << "Note: Invalid score for student ID 2 was converted to 0." << std::endl;

    printSectionTitle("Students After Score Updates");
    manager.printAllStudentsWithHeader();

    printSectionTitle("Academic Report");
    manager.printAcademicReport(passingScore, excellentScore);

    printSectionTitle("Removing Students");

    removeStudentAndPrintResult(manager, 1);

    removeStudentAndPrintResult(manager, 999);

    printSectionTitle("Final Student List");
    manager.printAllStudentsWithHeader();

    std::cout << "\nProgram finished successfully." << std::endl;

    return 0;

}