#include "Dog.hpp"

Dog::Dog(): Animal("Dog"), _name("Griffin")
{
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(std::string name): Animal("Dog"), _name(name)
{
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(Dog const &copy)
{
	_name = copy._name;
	type = copy.type;
	std::cout << "Dog Copie constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &a)
{
	this->type = a.type;
	this->_name = a._name;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "WOUAF WOUAF!" << std::endl;
}