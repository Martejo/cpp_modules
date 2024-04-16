#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ): ClapTrap(name)
{
	this->_attackDamage = 30;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap( FragTrap &copy ): ClapTrap(copy)
{
	std::cout << "Copy FragTrap constructor called" << std::endl;
}

void	FragTrap::attack( const std::string &target )
{
	if (!_energyPoints)
		std::cout << "FragTrap " << _Name << " not enough energy point!" << std::endl;
	else if (!_hitPoints)
		std::cout << "FragTrap " << _Name << " not enough hit point!" << std::endl;
	else
	{
		std::cout << "FragTrap " << _Name << " attacks " << target
			<< ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
}

void	FragTrap::highFivesGuys( void )
{
		std::cout << "FragTrap " << _Name << " is giving a high Five !" << std::endl;
}

FragTrap &FragTrap::operator=( FragTrap &a )
{
	_Name = a._Name;
	_attackDamage = a._attackDamage;
	_energyPoints = a._energyPoints;
	_hitPoints = a._hitPoints;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}