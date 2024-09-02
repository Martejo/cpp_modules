#include <string>
#include <iostream>
#include "iter.hpp"

template< typename T >
void print( T const & x )
{
	std::cout << x << std::endl;
	return;
}

int	main( void )
{
	{
		std::cout << "---- TEST CHAR ---\n" << std::endl;
		char table[6] = {'c', 'o', 'u', 'c', 'o', 'u'};
		::iter<char>(table, 8, print<char>);
		std::cout << std::endl;
	}
	{
		std::cout << "---- TEST INT ----\n" << std::endl;
		int table[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

		::iter<int>(table, 9, print<int>);
		std::cout << std::endl;
	}
	{
		std::cout << "---- TEST DOUBLE ----\n" << std::endl;
		double table[8] = {1.25, 2.25, 3.45, 4.43, 5.45, 6.34, 7.77, 8.65};

		::iter<double>(table, 8, print<double>);
		std::cout << std::endl;
	}
	return (0);
}