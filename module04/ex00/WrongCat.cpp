#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(), _name("Fake Griffin")
{
	std::cout << "WrongCat Default constructor called" << std::endl;
}


WrongCat::WrongCat(std::string name): WrongAnimal(), _name(name)
{

}

WrongCat::WrongCat(const WrongCat &copy)
{
	this->_name = copy._name;
	this->_type = copy._type;
	std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &a)
{
	this->_type = a._type;
	this->_name = a._name;
	std::cout << "Operator WrongCat called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "I'm not a cat" << std::endl;
}