#include "ConsoleMenu.h"

#include <iostream>

#include "InputValidator.h"


void ConsoleMenu::printWelcomeMessage() const
{
	std::cout << "\nWelcome to the Academic Record Management System!"
		<< std::endl;

	std::cout << "Manage students, update records, and generate academic reports."
		<< std::endl;

}


void ConsoleMenu::printMainMenu() const
{
	std::cout << "\nMain Menu" << std::endl;
	std::cout << "---------" << std::endl;
	std::cout << "1. Add student" << std::endl;
	std::cout << "2. Show all students" << std::endl;
	std::cout << "3. Search student by ID" << std::endl;
	std::cout << "4. Update student name" << std::endl;
	std::cout << "5. Update student score" << std::endl;
	std::cout << "6. Remove student" << std::endl;
	std::cout << "7. Show academic report" << std::endl;
	std::cout << "8. Save students to CSV" << std::endl;
	std::cout << "9. Load students from CSV" << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cout << "Choose an option: ";

}


int ConsoleMenu::readMenuChoice() const
{
	int choice = -1;

	std::cin >> choice;

	return choice;

}


std::string ConsoleMenu::readFilePath() const
{
	std::string filePath;

	std::cout << "Enter CSV file path: ";

	std::getline
	(
		std::cin >> std::ws,
		filePath
	);

	return filePath;

}


bool ConsoleMenu::isValidMenuChoice
(
	int choice
) const
{
	return InputValidator::isMenuChoiceInRange
	(
		choice,
		0,
		9
	);

}


void ConsoleMenu::printInvalidMenuChoiceMessage() const
{
	std::cout << "\nInvalid menu option. Please choose a number from 0 to 9."
		<< std::endl;

}


void ConsoleMenu::printGoodbyeMessage() const
{
	std::cout << "\nThank you for using the Academic Record Management System."
		<< std::endl;

	std::cout << "Program finished successfully."
		<< std::endl;

}