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

	// - Compare operators
	bool	operator>( const Fixed &a) const;
	bool	operator<( const Fixed &a) const;
	bool	operator<=( const Fixed &a) const;
	bool	operator>=( const Fixed &a) const;
	bool	operator==( const Fixed &a) const;
	bool	operator!=( const Fixed &a) const;

	// Arithmetic operators
	Fixed	operator+( const Fixed &a) const;
	Fixed	operator-( const Fixed &a) const;
	Fixed	operator*( const Fixed &a) const;
	Fixed	operator/( const Fixed &a) const;

	// Incre/Decrementation operators
	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	
	static Fixed		&min( Fixed& a, Fixed& b );
	static const Fixed	&min( const Fixed& a, const Fixed& b );
	static Fixed		&max( Fixed& a, Fixed& b );
	static const Fixed	&max( const Fixed& a, const Fixed& b );
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);




#endif