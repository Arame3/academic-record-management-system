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

    std::cout << "Student count: " << manager.getCount() << std::endl;

    manager.printAll();

    return 0;

}