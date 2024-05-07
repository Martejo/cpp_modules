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

//getter
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedNbr);
}

//setter
void Fixed::setRawBits( int const raw )
{
	this->_fixedNbr = raw;
}

//Surcharge d' operateur
Fixed& Fixed::operator=(const Fixed& source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedNbr = source.getRawBits();
	return (*this);
}
