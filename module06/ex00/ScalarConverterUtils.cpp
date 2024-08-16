#include "ScalarConverter.hpp"

void ScalarConverter::detectImpossibleConversion(const std::string &literal)
{
	std::string low_l = ScalarConverter::strToLower(literal);

	// Vérification pour les valeurs spéciales
	if (low_l == "inf" || low_l == "-inf" || low_l == "+inf" || low_l == "nan" ||
		low_l == "inff" || low_l == "-inff" || low_l == "+inff" || low_l == "nanf") {
		return;
	}

	// Vérifier si '+' ou '-' est en début de chaîne
	if ((literal[0] == '+' || literal[0] == '-') && literal.size() > 1) {
		std::string::size_type i;
		for (i = 1; i < literal.size(); ++i) {
			if (literal[i] == '+' || literal[i] == '-') {
				throw ScalarConverter::ImpossibleConversionException();
			}
		}
	}

	bool point_found = false;
	std::string::size_type i;
	for (i = 0; i < literal.size(); ++i) {
		char c = literal[i];

		// Si ce n'est pas un chiffre, un point, un 'f', un '+' ou un '-'
		if (!std::isdigit(c) && c != '.' && c != 'f' && c != '+' && c != '-') {
			throw ScalarConverter::ImpossibleConversionException();
		}

		// Vérifier la position de 'f'
		if (c == 'f' && i != literal.size() - 1) {
			throw ScalarConverter::ImpossibleConversionException();
		}

		// Vérifier s'il y a plus d'un point
		if (c == '.') {
			if (point_found) {
				throw ScalarConverter::ImpossibleConversionException();
			}
			point_found = true;
		}
	}

	// Si un 'f' est présent mais pas en dernière position
	if (literal.find('f') != std::string::npos && literal[literal.size() - 1] != 'f') {
		throw ScalarConverter::ImpossibleConversionException();
	}
}

void ScalarConverter::detectOverflow(const std::string &literal) 
    {
        std::strtod(literal.c_str(), NULL);
        if (errno == ERANGE)
            throw ScalarConverter::OverflowException();
    }

int ScalarConverter::choosePrecision(const std::string &literal)
{
	int	i = 0;

	if (literal.find_first_of('.') == std::string::npos)
		return (1);
	for (size_t j = literal.find_first_of('.'); j < literal.length(); j++)
	{
		if (std::isdigit(literal[j]))
			i++;
	}
	if (i == 0)
		return(1);
	return (i);
}

std::string ScalarConverter::strToLower(const std::string &literal)
{
	std::string low_l = literal;
	for (size_t i = 0; i < low_l.length(); i++)
		low_l[i] = std::tolower(static_cast<unsigned char>(literal[i]));
	return (low_l);
}