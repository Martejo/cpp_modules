/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:33:04 by gemartel          #+#    #+#             */
/*   Updated: 2024/04/23 16:15:46 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
{
	this->_name = "<namelessDiamond>";
	this->_hitPoints = _hitPointsHeritage;
	this->_energyPoints = _energy_points_heritage;
	this->_attackDamage = _attackDmgHeritage;
	std::cout << _name << " is created." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << _name << " is destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	this->_name = name;
	this->_hitPoints = _hitPointsHeritage;
	this->_energyPoints = _energy_points_heritage;
	this->_attackDamage = _attackDmgHeritage;
	std::cout << _name << " is created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &p)
{
	this->_name = p._name;
	this->_hitPoints = p._hitPoints;
	this->_energyPoints = p._energyPoints;
	this->_attackDamage = p._attackDamage;
	std::cout << _name << " is created." << std::endl;
}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap &p)
{
	this->_name = p._name;
	this->_hitPoints = p._hitPoints;
	this->_energyPoints = p._energyPoints;
	this->_attackDamage = p._attackDamage;
	std::cout << _name << " is created." << std::endl;
	return *this;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My ClapTrapname is : " << ClapTrap::_Name << ", DiamondTrap name is : " << this->_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	std::cout << "Called by Diamond:";
	ScavTrap::attack(target);
};