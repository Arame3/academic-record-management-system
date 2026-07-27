#pragma once

#include <filesystem>
#include <ostream>

#include "InputReader.h"


class CsvFilePathReader
{
private:

	InputReader& inputReader;

	std::ostream& output;

public:

	CsvFilePathReader
	(
		InputReader& inputReader,

		std::ostream& output
	);

	CsvFilePathReader
	(
		const CsvFilePathReader& other
	) = delete;

	CsvFilePathReader& operator=
		(
			const CsvFilePathReader& other
			) = delete;

	std::filesystem::path readInputPath() const;

	std::filesystem::path readOutputPath() const;

};