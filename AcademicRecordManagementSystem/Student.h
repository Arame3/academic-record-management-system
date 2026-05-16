#pragma once

#include <string>
#include <ostream>

class Student
{

private:

    int id;
    
    std::string name;

    double score;

public:

    Student();

    Student(int id, const std::string& name, double score);


    int getId() const;

    std::string getName() const;

    double getScore() const;



    bool hasPassingScore(double passingScore) const;




    void setId(int id);

    void setName(const std::string& name);

    void setScore(double score);



    friend std::ostream& operator<<(std::ostream& out, const Student& student);

};