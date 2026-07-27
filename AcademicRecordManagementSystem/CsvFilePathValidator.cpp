#include "CsvFilePathValidator.h"

#include <algorithm>
#include <cctype>
#include <system_error>


std::string CsvFilePathValidator::toLowerCopy
(
	const std::string& value

)
{
	std::string result = value;

	std::transform
	(
		result.begin(),

		result.end(),

		result.begin(),
		[]
		(
			unsigned char character
			)
		{
			return static_cast<char>
				(
					std::tolower(character)
					);

		}
	);

	return result;

}


bool CsvFilePathValidator::hasCsvExtension
(
	const std::filesystem::path& filePath

)
{
	std::string extension = toLowerCopy
	(
		filePath.extension().string()
	);

	return extension == ".csv";

}


CsvPathValidationResult CsvFilePathValidator::validateInputPath
(
	const std::filesystem::path& filePath

)
{
	if (filePath.empty())
	{
		return
		{
			CsvPathValidationError::EmptyPath
		};

	}

	if (!filePath.has_filename())
	{
		return
		{
			CsvPathValidationError::MissingFileName
		};

	}

	if (!hasCsvExtension(filePath))
	{
		return
		{
			CsvPathValidationError::InvalidExtension
		};

	}

	std::error_code errorCode;

	bool fileExists = std::filesystem::exists
	(
		filePath,

		errorCode
	);

	if (errorCode)
	{
		return
		{
			CsvPathValidationError::FileSystemError
		};
	}

	if (!fileExists)
	{
		return
		{
			CsvPathValidationError::FileNotFound
		};
	}

	bool regularFile = std::filesystem::is_regular_file
	(
		filePath,

		errorCode
	);

	if (errorCode)
	{
		return
		{
			CsvPathValidationError::FileSystemError

		};
	}

	if (!regularFile)
	{
		return
		{
			CsvPathValidationError::NotRegularFile

		};
	}

	return {};

}


CsvPathValidationResult CsvFilePathValidator::validateOutputPath
(
	const std::filesystem::path& filePath

)
{
	if (filePath.empty())
	{
		return
		{
			CsvPathValidationError::EmptyPath

		};

	}

	if (!filePath.has_filename())
	{
		return
		{
			CsvPathValidationError::MissingFileName

		};

	}

	if (!hasCsvExtension(filePath))
	{
		return
		{
			CsvPathValidationError::InvalidExtension

		};

	}

	std::error_code errorCode;

	std::filesystem::path parentPath = filePath.parent_path();

	if (parentPath.empty())
	{
		parentPath = std::filesystem::current_path
		(
			errorCode
		);

		if (errorCode)
		{
			return
			{
				CsvPathValidationError::FileSystemError
			};
		}
	}

	bool parentExists = std::filesystem::exists
	(
		parentPath,

		errorCode

	);

	if (errorCode)
	{
		return
		{
			CsvPathValidationError::FileSystemError

		};
	}

	if (!parentExists)
	{
		return
		{
			CsvPathValidationError::ParentDirectoryNotFound

		};
	}

	bool parentIsDirectory = std::filesystem::is_directory
	(
		parentPath,

		errorCode
	);

	if (errorCode)
	{
		return
		{
			CsvPathValidationError::FileSystemError

		};
	}

	if (!parentIsDirectory)
	{
		return
		{
			CsvPathValidationError::ParentPathIsNotDirectory

		};
	}

	bool outputExists = std::filesystem::exists
	(
		filePath,

		errorCode
	);

	if (errorCode)
	{
		return
		{
			CsvPathValidationError::FileSystemError

		};
	}

	if (!outputExists)
	{
		return {};

	}

	bool outputIsRegularFile = std::filesystem::is_regular_file
	(
		filePath,

		errorCode
	);

	if (errorCode)
	{
		return
		{
			CsvPathValidationError::FileSystemError

		};
	}

	if (!outputIsRegularFile)
	{
		return
		{
			CsvPathValidationError::NotRegularFile

		};
	}

	return {};

}