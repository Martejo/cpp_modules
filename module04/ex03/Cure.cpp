/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:04:40 by gemartel          #+#    #+#             */
/*   Updated: 2024/05/06 16:38:59 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Default constructor Cure\n";
}

Cure::Cure(const Cure& copy): AMateria(copy._type)
{
	if (this != &copy)
		*this = copy;
}

// Assignment operator overload
Cure& Cure::operator=(const Cure& a)
{
	this->AMateria::operator=(a);
	return *this;
}

// Destructor
Cure::~Cure()
{
	std::cout << "Cure destructor" << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}