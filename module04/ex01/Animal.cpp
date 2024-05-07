/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:06:34 by gemartel          #+#    #+#             */
/*   Updated: 2024/04/24 11:35:07 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Worms")
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(std::string type): type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( Animal &copy ): type(copy.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=( Animal &a)
{
	this->type = a.type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}