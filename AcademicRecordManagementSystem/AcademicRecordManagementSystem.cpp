#include <iostream>
#include <string>

#include "ConsoleMenu.h"
#include "CsvFilePathReader.h"
#include "InputReader.h"
#include "Logger.h"
#include "Student.h"
#include "StudentInputReader.h"
#include "StudentManager.h"
#include "StudentPersistenceLoadResult.h"
#include "StudentPersistenceService.h"


static void printSectionTitle
(
	const std::string& title
)
{
	std::cout << "\n============================================================"
		<< std::endl;

	std::cout << "                    "
		<< title
		<< std::endl;

	std::cout << "============================================================"
		<< std::endl;

}


static void addStudentAndPrintResult
(
	StudentManager& manager,
	const Student& student
);


static void updateStudentNameAndPrintResult
(
	StudentManager& manager,
	int id,
	const std::string& newName
);


static void updateStudentScoreAndPrintResult
(
	StudentManager& manager,
	int id,
	double newScore
);


static void removeStudentAndPrintResult
(
	StudentManager& manager,
	int id
);


static void saveStudentsAndPrintResult
(
	CsvFilePathReader& csvFilePathReader,
	StudentPersistenceService& persistenceService
);


static void loadStudentsAndPrintResult
(
	CsvFilePathReader& csvFilePathReader,
	StudentPersistenceService& persistenceService
);


static void handleMenuChoice
(
	int choice,
	StudentManager& manager,
	StudentInputReader& studentInputReader,
	CsvFilePathReader& csvFilePathReader,
	StudentPersistenceService& persistenceService,
	double passingScore,
	double excellentScore
)
{
	switch (choice)
	{
	case 1:
	{
		Student student =
			studentInputReader.readStudent();

		addStudentAndPrintResult
		(
			manager,
			student
		);

		break;
	}

	case 2:
		std::cout << "Showing all students..."
			<< std::endl;

		manager.printAllStudentsWithHeader();

		break;

	case 3:
	{
		int id =
			studentInputReader.readStudentId();

		manager.printStudentById
		(
			id
		);

		break;
	}

	case 4:
	{
		int id =
			studentInputReader.readStudentId();

		std::string newName =
			studentInputReader.readStudentName();

		updateStudentNameAndPrintResult
		(
			manager,
			id,
			newName
		);

		break;
	}

	case 5:
	{
		int id =
			studentInputReader.readStudentId();

		double newScore =
			studentInputReader.readStudentScore();

		updateStudentScoreAndPrintResult
		(
			manager,
			id,
			newScore
		);

		break;
	}

	case 6:
	{
		int id =
			studentInputReader.readStudentId();

		removeStudentAndPrintResult
		(
			manager,
			id
		);

		break;
	}

	case 7:
		std::cout << "Showing academic report..."
			<< std::endl;

		manager.printAcademicReport
		(
			passingScore,
			excellentScore
		);

		break;

	case 8:
		saveStudentsAndPrintResult
		(
			csvFilePathReader,
			persistenceService
		);

		break;

	case 9:
		loadStudentsAndPrintResult
		(
			csvFilePathReader,
			persistenceService
		);

		break;

	case 0:
		std::cout << "Exit selected."
			<< std::endl;

		break;

	default:
		std::cout << "Invalid menu option."
			<< std::endl;

		break;
	}

}


static void addStudentAndPrintResult
(
	StudentManager& manager,
	const Student& student
)
{
	if (manager.addStudent(student))
	{
		std::cout << "Student added successfully: "
			<< student.getName()
			<< " (ID: "
			<< student.getId()
			<< ")"
			<< std::endl;
	}
	else
	{
		std::cout << "Could not add student: "
			<< student.getName()
			<< ". Invalid or duplicate ID."
			<< std::endl;
	}

}


static void updateStudentNameAndPrintResult
(
	StudentManager& manager,
	int id,
	const std::string& newName
)
{
	if (
		manager.updateStudentNameById
		(
			id,
			newName
		)
		)
	{
		std::cout << "Successfully updated name for student ID "
			<< id
			<< "."
			<< std::endl;
	}
	else
	{
		std::cout << "Could not update name for student ID "
			<< id
			<< ". Student not found."
			<< std::endl;
	}

}


static void updateStudentScoreAndPrintResult
(
	StudentManager& manager,
	int id,
	double newScore
)
{
	if (
		manager.updateStudentScoreById
		(
			id,
			newScore
		)
		)
	{
		std::cout << "Successfully updated score for student ID "
			<< id
			<< "."
			<< std::endl;
	}
	else
	{
		std::cout << "Could not update score for student ID "
			<< id
			<< ". Student not found."
			<< std::endl;
	}

}


static void removeStudentAndPrintResult
(
	StudentManager& manager,
	int id
)
{
	if (
		manager.removeStudentById
		(
			id
		)
		)
	{
		std::cout << "Successfully removed student with ID "
			<< id
			<< "."
			<< std::endl;
	}
	else
	{
		std::cout << "Could not remove student with ID "
			<< id
			<< ". Student not found."
			<< std::endl;
	}

}


static void saveStudentsAndPrintResult
(
	CsvFilePathReader& csvFilePathReader,
	StudentPersistenceService& persistenceService
)
{
	std::string filePath =
		csvFilePathReader.readOutputPath().string();

	if (
		persistenceService.saveStudentsToCsv
		(
			filePath
		)
		)
	{
		std::cout << "Student records were saved successfully to: "
			<< filePath
			<< std::endl;
	}
	else
	{
		std::cout << "Could not save student records to: "
			<< filePath
			<< std::endl;

		std::cout << "Please check the file path and write permissions."
			<< std::endl;
	}

}


static void loadStudentsAndPrintResult
(
	CsvFilePathReader& csvFilePathReader,
	StudentPersistenceService& persistenceService
)
{
	std::string filePath =
		csvFilePathReader.readInputPath().string();

	StudentPersistenceLoadResult result =
		persistenceService.loadStudentsFromCsv
		(
			filePath
		);

	if (!result.wasFileOpened())
	{
		std::cout << "Could not open CSV file: "
			<< filePath
			<< std::endl;

		std::cout << "Please check whether the file exists and the path is correct."
			<< std::endl;

		return;
	}

	std::cout << "CSV file processed successfully."
		<< std::endl;

	std::cout << "Processed lines: "
		<< result.fileLoadResult.processedLineCount
		<< std::endl;

	std::cout << "Valid CSV records: "
		<< result.fileLoadResult.loadedCount
		<< std::endl;

	std::cout << "Malformed CSV records: "
		<< result.fileLoadResult.rejectedCount
		<< std::endl;

	std::cout << "Imported students: "
		<< result.importResult.importedCount
		<< std::endl;

	std::cout << "Rejected students: "
		<< result.importResult.rejectedCount
		<< std::endl;

	if (result.completedWithoutRejections())
	{
		std::cout << "All student records were imported successfully."
			<< std::endl;
	}
	else if (result.hasImportedAny())
	{
		std::cout << "Import completed with some rejected records."
			<< std::endl;
	}
	else
	{
		std::cout << "No student records were imported."
			<< std::endl;
	}

}


int main()
{
	printSectionTitle
	(
		"Academic Record Management System"
	);

	StudentManager manager;

	ConsoleMenu menu;

	InputReader inputReader
	(
		std::cin,
		std::cout
	);

	StudentInputReader studentInputReader
	(
		inputReader
	);

	CsvFilePathReader csvFilePathReader
	(
		inputReader,
		std::cout
	);

	Logger logger
	(
		"academic_record_system.log"
	);

	StudentPersistenceService persistenceService
	(
		manager,
		logger
	);

	const double passingScore = 40.0;

	const double excellentScore = 90.0;

	menu.printWelcomeMessage();

	int menuChoice = -1;

	while (menuChoice != 0)
	{
		menu.printMainMenu();

		menuChoice =
			inputReader.readNumber<int>
			(
				"",
				0,
				9
			);

		std::cout << std::endl;

		handleMenuChoice
		(
			menuChoice,
			manager,
			studentInputReader,
			csvFilePathReader,
			persistenceService,
			passingScore,
			excellentScore
		);
	}

	menu.printGoodbyeMessage();

	return 0;

}