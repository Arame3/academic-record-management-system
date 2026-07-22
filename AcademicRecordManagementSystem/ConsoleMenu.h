#pragma once

class ConsoleMenu
{
public:

    void printWelcomeMessage() const;

    void printMainMenu() const;

    int readMenuChoice() const;

    bool isValidMenuChoice(int choice) const;

    void printInvalidMenuChoiceMessage() const;

    void printGoodbyeMessage() const;
};