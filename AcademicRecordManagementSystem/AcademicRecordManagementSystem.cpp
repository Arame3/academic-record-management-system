#include <iostream>
#include "Student.h"

int main()
{
    Student s1;
    Student s2("Ani", 95.5);
    Student s3("Aram", 150.0);

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;

    s1.setName("Mane");
    s1.setScore(88.5);

    std::cout << s1 << std::endl;

    return 0;
}