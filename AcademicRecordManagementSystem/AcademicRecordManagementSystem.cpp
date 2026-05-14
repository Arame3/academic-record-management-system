#include <iostream>
#include "Student.h"
#include "StudentManager.h"


int main()
{

    std::cout << "========================================================================================================================" << std::endl;
    std::cout << "                                Academic Record Management System" << std::endl;
    std::cout << "========================================================================================================================" << std::endl;

    StudentManager manager;

    std::cout << "\nInitial student list:" << std::endl;
    
    manager.printAll();

    std::cout << "\nAdding students..." << std::endl;

    manager.addStudent(Student("Ani", 95.5));
   
    std::cout << "Student added: Ani" << std::endl;

    manager.addStudent(Student("Aram", 150.0));
    
    std::cout << "Student added: Aram" << std::endl;
    std::cout << "Note: Aram had an invalid score, so it was set to 0." << std::endl;

    manager.addStudent(Student("Mane", 88.5));
    
    std::cout << "Student added: Mane" << std::endl;

    std::cout << "\nCurrent student count: "
        << manager.getCount()
        << std::endl;

    std::cout << "\nCurrent students:" << std::endl;
    
    manager.printAll();

    std::cout << "\nSearching students..." << std::endl;

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

    std::cout << "\nUpdating student scores..." << std::endl;

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

    std::cout << "\nStudents after updates:" << std::endl;
    
    manager.printAll();


    std::cout << "\nStatistics:" << std::endl;
    std::cout << "Average score: "
        << manager.getAverageScore()
        << std::endl;

    std::cout << "Best student index: "
        << manager.findBestStudentIndex()
        << std::endl;

    std::cout << "\nRemoving students..." << std::endl;

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

    std::cout << "\nStudent count after removal: "
        << manager.getCount()
        << std::endl;

    std::cout << "\nFinal student list:" << std::endl;
    
    manager.printAll();

    std::cout << "\nProgram finished successfully." << std::endl;

    return 0;
}