#include "Fixed.hpp"

//Constructeur par defaut
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedNbr = 0;
}

//Destructeur
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


//Constructeur par copie
Fixed::Fixed(const Fixed& source)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedNbr = value << _fixedBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
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

Fixed& Fixed::operator=(const Fixed& source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedNbr = source.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}