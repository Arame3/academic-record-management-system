#include "InputValidator.h"

#include <algorithm>
#include <cctype>


bool InputValidator::isValidId
(
	int id
)
{
	return id > 0;

}


bool InputValidator::isValidScore
(
	double score
)
{
	return score >= 0.0 && score <= 100.0;

}


bool InputValidator::isBlank
(
	const std::string& value

)
{
	if (value.empty())
	{
		return true;

	}

	return std::all_of
	(
		value.begin(),
		value.end(),
		[]
		(
			unsigned char character
		)
		{
			return std::isspace(character) != 0;

		}
	);

}


bool InputValidator::isNotBlank
(
	const std::string& value

)
{
	return !isBlank(value);

}


bool InputValidator::isValidName
(
	const std::string& name

)
{
	return isNotBlank(name);


}


bool InputValidator::isMenuChoiceInRange
(
	int choice,

	int minimumChoice,

	int maximumChoice
)
{
	return choice >= minimumChoice
		&& choice <= maximumChoice;

}