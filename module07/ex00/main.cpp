#include "Templates.hpp"
#include <iostream>
#include <string>

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


int main( void )
{
	int a = 2;
	int b = 3;
	std::cout << BOLD << CYAN << "<=== BEFORE SWAP ===>" << RESET << std::endl;

	std::cout  << BOLD << "a = " << a << " b = " << b << RESET << std::endl;
	::swap( a, b );
	std::cout << BOLD << CYAN << "\n<=== AFTER SWAP ===>" << RESET << std::endl;

	std::cout << BOLD << "a = " << a << ", b = " << b << RESET << std::endl;

	std::cout << BOLD << CYAN << "\n<=== TEST MIN ===>" << RESET << std::endl;

	std::cout << BOLD <<  "min( a, b ) = " << ::min( a, b ) << RESET << std::endl;

	std::cout << BOLD << CYAN << "\n<=== TEST MAX ===>" << RESET << std::endl;

	std::cout << BOLD << "max( a, b ) = " << ::max( a, b ) << RESET << std::endl;

	std::cout << BOLD << CYAN << "\n<=== STRING BEFORE SWAP ===>" << RESET << std::endl;
	
	std::string c = "chaine1";

	std::string d = "chaine2";
	
	std::cout << BOLD << "c = " << c << " , d = " << d << RESET << std::endl;
	
	::swap(c, d);
	
	std::cout << BOLD << CYAN << "\n<=== STRING AFTER SWAP ===>" << RESET << std::endl;

	std::cout << BOLD << "c = " << c << ", d = " << d << RESET << std::endl;

	std::cout << BOLD << CYAN << "\n<=== STRING TEST MIN ===>" << RESET << std::endl;

	std::cout << BOLD << "min( c, d ) = " << ::min( c, d ) << RESET <<  std::endl;

	std::cout << BOLD << CYAN << "\n<=== STRING TEST MAX ===>" << RESET << std::endl;

	std::cout << BOLD << "max( c, d ) = " << ::max( c, d ) << RESET << std::endl;

	return 0;
}