#include <iostream>
#include "Student.h"
#include "StudentManager.h"


int main()
{
    StudentManager manager;

    manager.printAll();

    manager.addStudent(Student("Ani", 95.5));
    manager.addStudent(Student("Aram", 150.0));
    manager.addStudent(Student("Mane", 88.5));

    std::cout << "Student count: "
        << manager.getCount()
        << std::endl;

    manager.printAll();

    std::cout << "Average score: "
        << manager.getAverageScore()
        << std::endl;

    std::cout << "Best student index: "
        << manager.findBestStudentIndex()
        << std::endl;

    std::cout << "Ani index: "
        << manager.findStudentIndexByName("Ani")
        << std::endl;

    std::cout << "David index: "
        << manager.findStudentIndexByName("David")
        << std::endl;

    bool updatedMane = manager.updateStudentScore("Mane", 99.0);

    std::cout << "Updated Mane: "
        << updatedMane
        << std::endl;

    bool updatedDavid = manager.updateStudentScore("David", 90.0);

    std::cout << "Updated David: "
        << updatedDavid
        << std::endl;

    bool updatedAram = manager.updateStudentScore("Aram", 150.0);

    std::cout << "Updated Aram: "
        << updatedAram
        << std::endl;

    manager.printAll();

    std::cout << "Average score after update: "
        << manager.getAverageScore()
        << std::endl;

    std::cout << "Best student index after update: "
        << manager.findBestStudentIndex()
        << std::endl;

    bool removedAni = manager.removeStudentByName("Ani");

    std::cout << "Removed Ani: "
        << removedAni
        << std::endl;

    bool removedDavid = manager.removeStudentByName("David");

    std::cout << "Removed David: "
        << removedDavid
        << std::endl;

    std::cout << "Student count after removal: "
        << manager.getCount()
        << std::endl;

    manager.printAll();

    std::cout << "Average score after removal: "
        << manager.getAverageScore()
        << std::endl;

    std::cout << "Best student index after removal: "
        << manager.findBestStudentIndex()
        << std::endl;

    return 0;

}