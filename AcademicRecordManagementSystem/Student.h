#pragma once

#include <string>
#include <ostream>

class Student
{

private:
    
    std::string name;

    double score;

public:

    Student();

    Student(const std::string& name, double score);



    std::string getName() const;

    double getScore() const;



    void setName(const std::string& name);

    void setScore(double score);



    friend std::ostream& operator<<(std::ostream& out, const Student& student);

};