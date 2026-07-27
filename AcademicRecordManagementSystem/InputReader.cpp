#include "InputReader.h"

#include "InputValidator.h"


InputReader::InputReader
(
	std::istream& input,
	std::ostream& output
)
	: input(input), output(output)
{

}


std::string InputReader::readNonEmptyLine
(
	const std::string& prompt
)
{
	std::string value;

	while (true)
	{
		output << prompt;

		std::getline
		(
			input,
			value
		);

		if (InputValidator::isValidName(value))
		{
			return value;
		}

		output << "Input cannot be empty. Please try again."
			<< std::endl;
	}

}