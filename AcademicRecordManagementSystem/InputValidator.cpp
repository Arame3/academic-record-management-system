#include "InputValidator.h"

bool InputValidator::isValidId(int id)
{
    return id > 0;
}


bool InputValidator::isValidScore(double score)
{
    return score >= 0.0 && score <= 100.0;
}


bool InputValidator::isValidName(const std::string& name)
{
    return !name.empty();
}


bool InputValidator::isMenuChoiceInRange(int choice, int minChoice, int maxChoice)
{
    return choice >= minChoice && choice <= maxChoice;
}