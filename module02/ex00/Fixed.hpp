#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_fixedNbr;
		static const int	_fixedBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& source);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		Fixed& operator=(const Fixed& source);
};

#endif