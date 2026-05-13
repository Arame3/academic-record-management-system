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

    std::cout << "Student count: " << manager.getCount()
        << std::endl;

    manager.printAll();

    std::cout << "Ani index: "
        << manager.findStudentIndexByName("Ani")
        << std::endl;

    std::cout << "David index: "
        << manager.findStudentIndexByName("David")
        << std::endl;

    bool removedAni = manager.removeStudentByName("Ani");

    std::cout << "Removed Ani: " << removedAni << std::endl;

    bool removedDavid = manager.removeStudentByName("David");

    std::cout << "Removed David: " << removedDavid << std::endl;

    std::cout << "Student count after removal: "
        << manager.getCount()
        << std::endl;

    manager.printAll();

    return 0;

}