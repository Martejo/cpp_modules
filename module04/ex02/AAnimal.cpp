/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:06:34 by gemartel          #+#    #+#             */
/*   Updated: 2024/05/06 11:18:09 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): type("Worms")
{
	std::cout << "Default AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type): type(type)
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal( AAnimal &copy ): type(copy.type)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=( AAnimal &a)
{
	this->type = a.type;
	return (*this);
}

void	AAnimal::makeSound() const
{
	std::cout << "AAnimal sound" << std::endl;
}

std::string AAnimal::getType() const
{
	return this->type;
}