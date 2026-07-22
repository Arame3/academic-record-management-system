#pragma once

#include <string>

enum class ScoreCategory
{
    Invalid,

    Failed,

    Passed,

    Excellent
};


class AcademicPolicy
{
private:

    double passingScore;
    double excellentScore;

public:

    AcademicPolicy();

    AcademicPolicy(double passingScore, double excellentScore);


    double getPassingScore() const;

    double getExcellentScore() const;


    void setPassingScore(double passingScore);

    void setExcellentScore(double excellentScore);


    bool isScoreInValidRange(double score) const;

    bool isPassingScore(double score) const;

    bool isExcellentScore(double score) const;


    ScoreCategory getScoreCategory(double score) const;

    std::string scoreCategoryToString(ScoreCategory category) const;

};