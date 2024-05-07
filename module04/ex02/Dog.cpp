#include "Dog.hpp"

Dog::Dog(): AAnimal("Dog"), _name("Pumba")
{
	_brain = new(Brain);
	_brain->setBrainIdeas("EAT");
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(std::string name): AAnimal("Dog"), _name(name)
{
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(Dog const &copy)
{
	if (this != &copy)
		*this = copy;
	std::cout << "Dog Copie constructor called" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &a)
{
	this->type = a.type;
	this->_name = a._name;
	this->_brain = new Brain(*a._brain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "WOUAF WOUAF" << std::endl;
}

Brain const	*Dog::getBrain() const
{
	return (_brain);
}
