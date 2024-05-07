#include "Cat.hpp"

Cat::Cat(): AAnimal("Cat"), _name("Griffin")
{
	_brain = new Brain();
	_brain->setBrainIdeas("SLEEP");
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(std::string name): AAnimal("Cat"), _name(name)
{
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(Cat const &copy)
{
	_name = copy._name;
	type = copy.type;
	std::cout << "Cat Copie constructor called" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &a)
{
	this->type = a.type;
	this->_name = a._name;
	_brain = new Brain(*a._brain);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "MEOW MEOW" << std::endl;
}