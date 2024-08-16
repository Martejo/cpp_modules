
#include "ScalarConverter.hpp"

const char*	ScalarConverter::OverflowException::what( void ) const throw()
{
	return ("Error: The conversion will cause an overfow, try to pass a literal in range");
}

const char*	ScalarConverter::ImpossibleConversionException::what( void ) const throw()
{
	return ("Error: The conversion is impossible, the input don't match with any of this types {char, int, float, double}");
}
