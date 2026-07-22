#include <iostream>
#include <limits>
#include <string>

#include "Student.h"
#include "StudentManager.h"
#include "ConsoleMenu.h"


static void printSectionTitle(const std::string& title)
{
    std::cout << "\n============================================================" << std::endl;
    std::cout << "                    " << title << std::endl;
    std::cout << "============================================================" << std::endl;
}


static int readStudentId()
{
    int id = 0;

    std::cout << "Enter student ID: ";
    std::cin >> id;

    return id;
}


static std::string readStudentName()
{
    std::string name;

    std::cout << "Enter student name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    return name;
}


static double readStudentScore()
{
    double score = 0.0;

    std::cout << "Enter student score: ";
    std::cin >> score;

    return score;
}


static void addStudentAndPrintResult(StudentManager& manager, const Student& student);


static void updateStudentNameAndPrintResult(StudentManager& manager, int id, const std::string& newName);

static void updateStudentScoreAndPrintResult(StudentManager& manager, int id, double newScore);

static void removeStudentAndPrintResult(StudentManager& manager, int id);


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
    {
        int id = readStudentId();
        std::string name = readStudentName();
        double score = readStudentScore();

        addStudentAndPrintResult(manager, Student(id, name, score));

        if (score < 0.0 || score > 100.0)
        {
            std::cout << "Note: Invalid score was converted to 0." << std::endl;
        }

        break;
    }

    case 2:
        std::cout << "Showing all students..." << std::endl;
        manager.printAllStudentsWithHeader();
        break;

    case 3:
    {
        int id = readStudentId();

        manager.printStudentById(id);

        break;
    }

    case 4:
    {
        int id = readStudentId();
        std::string newName = readStudentName();

        updateStudentNameAndPrintResult(manager, id, newName);

        break;
    }

    case 5:
    {
        int id = readStudentId();
        double newScore = readStudentScore();

        updateStudentScoreAndPrintResult(manager, id, newScore);

        if (newScore < 0.0 || newScore > 100.0)
        {
            std::cout << "Note: Invalid score was converted to 0." << std::endl;
        }

        break;
    }

    case 6:
    {
        int id = readStudentId();

        removeStudentAndPrintResult(manager, id);

        break;
    }

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


static void addStudentAndPrintResult(StudentManager& manager, const Student& student)
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


static void updateStudentNameAndPrintResult(StudentManager& manager, int id, const std::string& newName)
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


static void updateStudentScoreAndPrintResult(StudentManager& manager, int id, double newScore)
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


static void removeStudentAndPrintResult(StudentManager& manager, int id)
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
    ConsoleMenu menu;

    menu.printWelcomeMessage();

 
    double passingScore = 40.0;
    double excellentScore = 90.0;

    printSectionTitle("Loading Demo Data");
    loadDemoData(manager);

    int menuChoice = -1;

    while (menuChoice != 0)
    {
        menu.printMainMenu();

        menuChoice = menu.readMenuChoice();

        if (menu.isValidMenuChoice(menuChoice))
        {
            std::cout << std::endl;
            handleMenuChoice(menuChoice, manager, passingScore, excellentScore);
        }
        else
        {
            menu.printInvalidMenuChoiceMessage();
        }
    }

    menu.printGoodbyeMessage();

    return 0;
}