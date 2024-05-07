/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:12:29 by gemartel          #+#    #+#             */
/*   Updated: 2024/05/06 16:09:05 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const std::string& name) : _name(name)
{
	std::cout << this->_name << " Default constructor Character\n";
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._materia[i])
			this->_materia[i] = other._materia[i]->clone();
		else
			this->_materia[i] = NULL;
			
	}
}

Character& Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		this->~Character();
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			if (rhs._materia[i])
				this->_materia[i] = rhs._materia[i]->clone();
			else
				this->_materia[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
	std::cout << "Character destructor" << std::endl;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!this->_materia[i])
			{
				this->_materia[i] = m;
				std::cout << "Character " << this->_name << " equipped with " << m->getType() << std::endl;
				return ;
			}
		}
		std::cout << "Character " << this->_name << " can't equip " << m->getType() << std::endl;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && this->_materia[idx])
	{
		std::cout << "Character " << this->_name << " unequipped " << this->_materia[idx]->getType() << std::endl;
		this->_materia[idx] = NULL;
	}
	else
		std::cout << "Character " << this->_name << " can't unequip" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && this->_materia[idx])
	{
		std::cout << "Character " << this->_name << " uses " << this->_materia[idx]->getType() << std::endl;
		this->_materia[idx]->use(target);
	}
	else
		std::cout << "Character " << this->_name << " can't use" << std::endl;
}

AMateria *Character::getMateria(int idx)
{
	return (this->_materia[idx]);
}