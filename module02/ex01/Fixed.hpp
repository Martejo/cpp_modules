#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_fixedNbr;
	static const int	_fixedBits = 8;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& source);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	Fixed& operator=(const Fixed& source);

	int	toInt(void) const;
	float toFloat(void) const;
};

 std::ostream& operator<<(std::ostream& os, const Fixed& obj);



#endif