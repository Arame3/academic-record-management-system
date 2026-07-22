#include "AcademicPolicy.h"

AcademicPolicy::AcademicPolicy()
    : passingScore(40.0), excellentScore(90.0)
{
}


AcademicPolicy::AcademicPolicy(double passingScore, double excellentScore)
    : passingScore(40.0), excellentScore(90.0)
{
    setPassingScore(passingScore);
    setExcellentScore(excellentScore);
}


double AcademicPolicy::getPassingScore() const
{
    return passingScore;
}


double AcademicPolicy::getExcellentScore() const
{
    return excellentScore;
}


void AcademicPolicy::setPassingScore(double passingScore)
{
    if (isScoreInValidRange(passingScore) && passingScore <= excellentScore)
    {
        this->passingScore = passingScore;
    }
}


void AcademicPolicy::setExcellentScore(double excellentScore)
{
    if (isScoreInValidRange(excellentScore) && excellentScore >= passingScore)
    {
        this->excellentScore = excellentScore;
    }
}


bool AcademicPolicy::isScoreInValidRange(double score) const
{
    return score >= 0.0 && score <= 100.0;
}


bool AcademicPolicy::isPassingScore(double score) const
{
    return isScoreInValidRange(score) && score >= passingScore;
}


bool AcademicPolicy::isExcellentScore(double score) const
{
    return isScoreInValidRange(score) && score >= excellentScore;
}


ScoreCategory AcademicPolicy::getScoreCategory(double score) const
{
    if (!isScoreInValidRange(score))
    {
        return ScoreCategory::Invalid;
    }

    if (isExcellentScore(score))
    {
        return ScoreCategory::Excellent;
    }

    if (isPassingScore(score))
    {
        return ScoreCategory::Passed;
    }

    return ScoreCategory::Failed;
}


std::string AcademicPolicy::scoreCategoryToString(ScoreCategory category) const
{
    switch (category)
    {
    case ScoreCategory::Invalid:
        return "Invalid";

    case ScoreCategory::Failed:
        return "Failed";

    case ScoreCategory::Passed:
        return "Passed";

    case ScoreCategory::Excellent:
        return "Excellent";

    default:
        return "Unknown";
    }
}