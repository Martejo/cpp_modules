#include <iostream>
#include "Fixed.hpp" 

int	main( void )
{
	std::cout << "\n---- Asked Tests ---\n" << std::endl;

	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << "\n---- My Tests ---\n" << std::endl;
	{
		Fixed c(2.5f);
		Fixed const d(4);

		std::cout << "c = " << c << " | d = " << d << std::endl;
		std::cout << "\nMin c and d => " << Fixed::min( c, d ) << std::endl;
		std::cout << "c + d => " << c + d << std::endl;
		std::cout << "c - d => " << c - d << std::endl;
		std::cout << "c / d => " << c / d << std::endl;

		std::cout << "c < d => " << (c < d) << std::endl;
		std::cout << "c > d => " << (c > d) << std::endl;
		std::cout << "c <= d => " << (c <= d) << std::endl;
		std::cout << "c >= d => " << (c >= d) << std::endl;
		std::cout << "c == d => " << (c == d) << std::endl;
		std::cout << "c != d => " << (c != d) << std::endl;
	}
	return 0;
}