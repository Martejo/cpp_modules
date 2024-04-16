#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	_Name = name;
	_energyPoints = 10;
	_hitPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap()
{
	_Name = "Morty";
	_energyPoints = 10;
	_hitPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &a )
{
	_Name = a._Name;
	_attackDamage = a._attackDamage;
	_energyPoints = a._energyPoints;
	_hitPoints = a._hitPoints;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}


void ClapTrap::print( void )
{
	std::cout << "name = " << _Name << " ";
	std::cout << "hit_points = " << _hitPoints << " ";
	std::cout << "attack = " << _attackDamage << " ";
	std::cout << "energy = " << _energyPoints << std::endl;
}

void ClapTrap::attack(const std::string& target)
{

	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << _Name << "attacks " << target;
		std::cout << ", causing " << _hitPoints << "points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "Oh no! ClapTrap is exhausted. It can no longer attack..." << std::endl;
	else
		std::cout << "☠️ClapTrap is ko☠️" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > amount)
		this->_hitPoints -= amount;
	else if (this->_hitPoints > 0)
		this->_hitPoints = 0;
	else
	{
		std::cout << "ClapTrap is ko, it can't take any more damage." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_Name << " was attacked and lost " << amount << " hit points, he now has " << this->_hitPoints << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0 && this->_hitPoints + amount <= 10)
	{
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_Name << " repaired itself and gained " << amount << " of hit points, he now has " << this->_hitPoints << "hit points." << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints > 0 && this->_hitPoints > 0 && this->_hitPoints + amount > 10)
	{
		this->_hitPoints = 10;
		std::cout << "ClapTrap " << this->_Name << " repaired itself and gained " << amount << " of hit points, he now has " << this->_hitPoints << "hit points." << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap is exhausted, he can't move anymore." << std::endl;
	else 
		std::cout << "ClapTrap can't be brought back to life." << std::endl;
}