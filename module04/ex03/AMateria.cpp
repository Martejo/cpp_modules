/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:38:46 by gemartel          #+#    #+#             */
/*   Updated: 2024/05/06 16:41:26 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): _type("Fire")
{
	
}

AMateria::AMateria(std::string const & type): _type(type)
{
	std::cout << "AMateria default constructor called" << std::endl;
}


AMateria::AMateria(const AMateria &copy)
{
	if (this != &copy)
		*this = copy;
}

AMateria &AMateria::operator=(const AMateria &a)
{
	(void)a;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
		(void)target;
}