#include <string>
#include <iostream>
#include "iter.hpp"

// Codes ANSI pour les couleurs
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD "\033[1m"


template< typename T >
void print( T const & x )
{
	std::cout << x << std::endl;
	return;
}

int	main( void )
{
	{
		std::cout << BOLD << CYAN "---- TEST CHAR ---\n" << RESET << std::endl;
		char table[6] = {'c', 'o', 'u', 'c', 'o', 'u'};
		::iter<char>(table, 8, print<char>);
		std::cout << std::endl;
	}
	{
		std::cout << BOLD << CYAN << "---- TEST INT ----\n" << RESET << std::endl;
		int table[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

		::iter<int>(table, 9, print<int>);
		std::cout << std::endl;
	}
	{
		std::cout << BOLD << CYAN << "---- TEST DOUBLE ----\n" << RESET << std::endl;
		double table[8] = {1.25, 2.25, 3.45, 4.43, 5.45, 6.34, 7.77, 8.65};

		::iter<double>(table, 8, print<double>);
		std::cout << std::endl;
	}
	return (0);
}