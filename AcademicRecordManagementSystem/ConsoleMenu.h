#pragma once

#include <string>


class ConsoleMenu
{
public:

	void printWelcomeMessage() const;

	void printMainMenu() const;

	int readMenuChoice() const;

	std::string readFilePath() const;

	bool isValidMenuChoice
	(
		int choice
	) const;

	void printInvalidMenuChoiceMessage() const;

	void printGoodbyeMessage() const;

};