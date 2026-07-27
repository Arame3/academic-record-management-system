#include "CsvPathValidationMessageProvider.h"


std::string CsvPathValidationMessageProvider::getMessage
(
	CsvPathValidationError error

)
{
	switch (error)
	{
	case CsvPathValidationError::None:
		return "The CSV file path is valid.";

	case CsvPathValidationError::EmptyPath:
		return "The file path cannot be empty.";

	case CsvPathValidationError::MissingFileName:
		return "The file path must contain a file name.";

	case CsvPathValidationError::InvalidExtension:
		return "The file must have a .csv extension.";

	case CsvPathValidationError::FileNotFound:
		return "The specified CSV file was not found.";

	case CsvPathValidationError::NotRegularFile:
		return "The specified path does not refer to a regular file.";

	case CsvPathValidationError::ParentDirectoryNotFound:
		return "The parent directory does not exist.";

	case CsvPathValidationError::ParentPathIsNotDirectory:
		return "The parent path is not a directory.";

	case CsvPathValidationError::FileSystemError:
		return "A file system error occurred while validating the path.";

	default:
		return "An unknown CSV path validation error occurred.";
	}

}