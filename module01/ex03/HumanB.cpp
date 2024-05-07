/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:58:02 by gemartel          #+#    #+#             */
/*   Updated: 2024/04/19 09:58:04 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string const &name) : name(name), weapon(NULL)
{
	return;
}

HumanB::~HumanB(void)
{
	return;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;

	return;
}

void HumanB::attack(void) const
{
	std::cout << this->name << " attacks with their ";

	if (this->weapon != NULL)
		std::cout << this->weapon->getType();
	else
		std::cout << "hands";

	std::cout << std::endl;

	return;
}