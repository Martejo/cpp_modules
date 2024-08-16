#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal)
{
        ScalarConverter::detectOverflow(literal);
        if(ScalarConverter::charDetected(literal))
            return;
        ScalarConverter::detectImpossibleConversion(literal);
        ScalarConverter::convertToInt(literal);
        ScalarConverter::convertToFloat(literal);
        ScalarConverter::convertToDouble(literal);
        ScalarConverter::convertToChar(literal);
}

bool ScalarConverter::charDetected(const std::string &literal)
{
	bool	is_char = (literal.length() == 1 && !std::isdigit(literal[0]));
	if (!is_char)
		return (0);
	char     charValue = static_cast<char>(literal[0]);

	std::cout << "int: " << static_cast<int>(charValue) << std::endl;
	std::cout << "float: " << static_cast<float>(charValue) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(charValue) << ".0" << std::endl;
	if (std::isprint(static_cast<int>(charValue))) {
			std::cout << "char: '" << charValue << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
	return (1);
}

void ScalarConverter::convertToInt(const std::string &literal) 
{
	std::stringstream ss(literal);
	int intValue;
	if (ss >> intValue) {
		std::cout << "int: " << intValue << std::endl;
	} else {
		std::cout << "int: impossible" << std::endl;
	}

}

void ScalarConverter::convertToFloat(const std::string &literal) 
{
	std::stringstream ss(literal);
	float floatValue;
	if (ss >> floatValue) {
		std::cout << std::fixed << std::setprecision(ScalarConverter::choosePrecision(literal));
		std::cout << "float: " << floatValue << "f" << std::endl;
	} else {
		if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
			std::cout << "float: " << literal << std::endl;
		} 
		else if (literal == "-inf" || literal == "+inf" || literal == "nan") {
			std::cout << "float: " << literal << "f" << std::endl;
		}
		else {
			std::cout << "float: impossible" << std::endl;
		}
	}
}


void ScalarConverter::convertToDouble(const std::string &literal) 
{
	std::stringstream ss(literal);
	double doubleValue;
	if (ss >> doubleValue) {
		std::cout << std::fixed << std::setprecision(ScalarConverter::choosePrecision(literal));
		std::cout << "double: " << doubleValue << std::endl;
	} 
	else
	{
		std::string low_l = ScalarConverter::strToLower(literal);
		if (low_l == "-inff" || low_l == "+inff" || low_l == "nanf") {
			std::cout << "double : " << low_l.substr(0, low_l.size() - 1) << std::endl;
		} 
		else if (low_l == "-inf" || low_l == "+inf" || low_l == "nan") {
			std::cout << "double : " << low_l << std::endl;
		}
		else {
			std::cout << "double: impossible" << std::endl;
		}
	}
}

void ScalarConverter::convertToChar(const std::string &literal) 
{
	int intValue;
	std::stringstream ss(literal);
	if (ss >> intValue && intValue >= 0 && intValue <= 127) {
		if (std::isprint(intValue)) {
			std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		}
	} else {
		std::cout << "char: impossible" << std::endl;
	}
}