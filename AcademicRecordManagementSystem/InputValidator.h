#pragma once

#include <string>

class InputValidator
{
public:

    static bool isValidId(int id);

    static bool isValidScore(double score);

    static bool isValidName(const std::string& name);

    static bool isMenuChoiceInRange(int choice, int minChoice, int maxChoice);

};