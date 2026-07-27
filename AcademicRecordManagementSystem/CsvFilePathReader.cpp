#include "CsvFilePathReader.h"

#include <string>

#include "CsvFilePathValidator.h"
#include "CsvPathValidationMessageProvider.h"


CsvFilePathReader::CsvFilePathReader
(
	InputReader& inputReader,
	std::ostream& output
)
	: inputReader(inputReader), output(output)
{

}


std::filesystem::path CsvFilePathReader::readInputPath() const
{
	while (true)
	{
		std::string pathText = inputReader.readNonEmptyLine
		(
			"Enter CSV input file path: "
		);

		std::filesystem::path filePath
		(
			pathText
		);

		CsvPathValidationResult result =
			CsvFilePathValidator::validateInputPath
			(
				filePath
			);

		if (result.isValid())
		{
			return filePath;
		}

		output << CsvPathValidationMessageProvider::getMessage
		(
			result.error
		)
			<< std::endl;
	}

}


std::filesystem::path CsvFilePathReader::readOutputPath() const
{
	while (true)
	{
		std::string pathText = inputReader.readNonEmptyLine
		(
			"Enter CSV output file path: "
		);

		std::filesystem::path filePath
		(
			pathText
		);

		CsvPathValidationResult result =
			CsvFilePathValidator::validateOutputPath
			(
				filePath
			);

		if (result.isValid())
		{
			return filePath;
		}

		output << CsvPathValidationMessageProvider::getMessage
		(
			result.error
		)
			<< std::endl;
	}

}