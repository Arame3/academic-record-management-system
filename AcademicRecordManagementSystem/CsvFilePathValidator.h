#pragma once

#include <filesystem>
#include <string>

#include "CsvPathValidationResult.h"


class CsvFilePathValidator
{
private:

	static std::string toLowerCopy
	(
		const std::string& value

	);

public:

	static bool hasCsvExtension
	(
		const std::filesystem::path& filePath

	);

	static CsvPathValidationResult validateInputPath
	(
		const std::filesystem::path& filePath

	);

	static CsvPathValidationResult validateOutputPath
	(
		const std::filesystem::path& filePath

	);

};