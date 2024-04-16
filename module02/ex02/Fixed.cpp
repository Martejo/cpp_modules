#include "Fixed.hpp"

//Constructeur par defaut
Fixed::Fixed()
{
	this->_fixedNbr = 0;
}

//Destructeur
Fixed::~Fixed()
{

}

//Constructeur par copie
Fixed::Fixed(const Fixed& source)
{
	*this = source;
}

Fixed::Fixed(const int value)
{
	this->_fixedNbr = value << _fixedBits;
}

Fixed::Fixed(const float value)
{
	this->_fixedNbr = roundf(value * (1 << _fixedBits));
}

int Fixed::getRawBits( void ) const
{
	return (this->_fixedNbr);
}


void Fixed::setRawBits( int const raw )
{
	this->_fixedNbr = raw;
}

int Fixed::toInt( void ) const
{
	return (_fixedNbr >> _fixedBits);
}

float Fixed::toFloat( void )const
{
	return ((float)this->_fixedNbr / (1 << _fixedBits));
}



std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

// Operator

Fixed& Fixed::operator=(const Fixed& source)
{
	if (this == &source)
		return (*this);
	this->_fixedNbr = source.getRawBits();
	return (*this);
}

bool	Fixed::operator>( const Fixed &a) const
{
	if (this->getRawBits() > a.getRawBits())
		return (true);
	return (false);
}
bool	Fixed::operator<( const Fixed &a) const
{
	if (this->getRawBits() < a.getRawBits())
		return (true);
	return (false);
}
bool	Fixed::operator<=( const Fixed &a) const
{
	if (this->getRawBits() <= a.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=( const Fixed &a) const
{
	if (this->getRawBits() >= a.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==( const Fixed &a) const
{
	if (this->getRawBits() == a.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=( const Fixed &a) const
{
	if (this->getRawBits() != a.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+( const Fixed &a) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() + a.getRawBits());
	return (result);
}

Fixed	Fixed::operator-( const Fixed &a) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() - a.getRawBits() );
	return (result);
}

Fixed	Fixed::operator*( const Fixed &a) const
{
	Fixed result;

	result =this->toFloat()* a.toFloat();
	//result.setRawBits(a.getRawBits() * this->getRawBits());
	return (result);
}

Fixed	Fixed::operator/( const Fixed &a) const
{
	Fixed result;

	result = this->toFloat() / a.toFloat();
	//result.setRawBits(a.getRawBits() / this->getRawBits());
	return (result);
}

Fixed& Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}


Fixed& Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	prev = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (prev);
}

Fixed Fixed::operator--(int)
{

	Fixed	prev = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (prev);
}

// Min/Max

Fixed	&Fixed::min( Fixed& a, Fixed& b )
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min( const Fixed& a, const Fixed& b )
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max( Fixed& a, Fixed& b )
{
	if (a < b)
		return (b);
	return (a);
}

const Fixed	&Fixed::max( const Fixed& a, const Fixed& b )
{
	if (a < b)
		return (b);
	return (a);
}
