#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>


class InputReader
{
private:

	std::istream& input;

	std::ostream& output;

public:

	InputReader
	(
		std::istream& input,
		std::ostream& output
	);

	InputReader
	(
		const InputReader& other
	) = delete;

	InputReader& operator=
		(
			const InputReader& other
			) = delete;

	template <typename T>
	T readNumber
	(
		const std::string& prompt,

		T minimumValue,

		T maximumValue
	)
	{
		static_assert
			(
				std::is_arithmetic_v<T>,
				"InputReader::readNumber requires an arithmetic type."
				);

		std::string line;

		while (true)
		{
			output << prompt;

			std::getline
			(
				input,
				line
			);

			std::istringstream lineStream
			(
				line
			);

			T value{};

			if (
				lineStream >> value
				&& lineStream >> std::ws
				&& lineStream.eof()
				&& value >= minimumValue
				&& value <= maximumValue
				)
			{
				return value;
			}

			output << "Invalid input. Enter a value from "
				<< minimumValue
				<< " to "
				<< maximumValue
				<< "."
				<< std::endl;
		}

	}

	std::string readNonEmptyLine
	(
		const std::string& prompt
	);

};