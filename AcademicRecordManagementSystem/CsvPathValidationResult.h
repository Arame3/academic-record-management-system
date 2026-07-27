#pragma once


enum class CsvPathValidationError
{
	None,

	EmptyPath,

	MissingFileName,

	InvalidExtension,

	FileNotFound,

	NotRegularFile,

	ParentDirectoryNotFound,

	ParentPathIsNotDirectory,

	FileSystemError
};


struct CsvPathValidationResult
{
	CsvPathValidationError error = CsvPathValidationError::None;

	bool isValid() const
	{
		return error == CsvPathValidationError::None;

	}

};