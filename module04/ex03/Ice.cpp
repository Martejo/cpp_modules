/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:00:26 by gemartel          #+#    #+#             */
/*   Updated: 2024/05/06 16:39:07 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Default constructor Ice\n"; 
}

Ice::Ice(const Ice& copy): AMateria(copy._type)
{
	if (this != &copy)
		*this = copy;
}

// Assignment operator overload
Ice& Ice::operator=(const Ice& a)
{
	this->AMateria::operator=(a);
	return *this;
}

// Destructor
Ice::~Ice()
{
	std::cout << "Ice destructor" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}