#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_attackDamage = 20;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ): ClapTrap(name)
{
	this->_attackDamage = 20;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap &copy ): ClapTrap(copy)
{
	std::cout << "Copy ScavTrap constructor called" << std::endl;
}

void	ScavTrap::attack( const std::string &target )
{
	if (!_energyPoints)
		std::cout << "ScavTrap " << _Name << " not enough energy point!" << std::endl;
	else if (!_hitPoints)
		std::cout << "ScavTrap " << _Name << " not enough hit point!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _Name << " attacks " << target
			<< ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate( void )
{
		std::cout << "ScavTrap " << _Name << " is guarding gate !" << std::endl;
}

ScavTrap &ScavTrap::operator=( ScavTrap &a )
{
	_Name = a._Name;
	_attackDamage = a._attackDamage;
	_energyPoints = a._energyPoints;
	_hitPoints = a._hitPoints;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}