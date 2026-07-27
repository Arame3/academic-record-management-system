#pragma once

#include <string>

#include "CsvPathValidationResult.h"


class CsvPathValidationMessageProvider
{
public:

	static std::string getMessage
	(
		CsvPathValidationError error

	);

};