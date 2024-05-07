/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:09:12 by gemartel          #+#    #+#             */
/*   Updated: 2024/05/06 11:23:08 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
# define BLUE "\033[1m\033[4m\033[34m"

/**
 * An abstract class is a class that cannot be instantiated and
 * serves as a template for other classes, defining pure virtual methods that derived classes must implement.
*/
int	main( void )
{
	{
		std::cout <<  BLUE <<"Constructor Destructor \033[0m \n" << std::endl;
		// Animal			error;
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		std::cout << "\n" << std::endl;
		delete j;
		delete i;
	}
	std::cout << "\n" << std::endl;
	{
		std::cout <<  BLUE <<"Creation of a table with cat and dog instances. \033[0m \n" << std::endl;
		AAnimal *tab[4];
		for (int i = 0; i < 4; i++)
		{
			if (i % 2 == 0)
				tab[i] = new Dog();
			else
				tab[i] = new Cat();
			tab[i]->makeSound();
		}
		std::cout << "\n" << std::endl;
		for (int i = 0; i < 4; i++)
			delete tab[i];
	}
	std::cout << "\n" << std::endl;
	{
		std::cout <<  BLUE <<"Copy deep instance. \033[0m \n" << std::endl;
		Dog	origin;
		Dog	copy(origin);
		std::cout << "\n" << std::endl;
		std::cout << origin.getBrain() << std::endl;
		std::cout << copy.getBrain() << std::endl;
		std::cout << "\n" << std::endl;
	}
	return (0);
}