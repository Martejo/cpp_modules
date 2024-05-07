/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:56:31 by gemartel          #+#    #+#             */
/*   Updated: 2024/04/19 09:56:35 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * Les références en C++ sont des alias pour des variables existantes,
 * permettant un accès direct à ces dernières sans nécessiter l'utilisation de pointeurs,
 * facilitant ainsi la manipulation de variables et
 * la transmission d'arguments à des fonctions de manière plus sûre et plus efficace.
*/
int main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*brainPtr = &brain;
	std::string	&brainRef = brain;

	std::cout << "This is memory adress of brain string---> " << &brain << std::endl;
	std::cout << "This is memory adress held by stringPTR---> " << brainPtr << std::endl;
	std::cout << "This is memory adress held by stringREF---> " << &brainRef << std::endl;
	std::cout << std::endl;
	std::cout << "Value of brain---> " << brain << std::endl;
	std::cout << "Value pointed by stringPTR---> " << *brainPtr << std::endl;
	std::cout << "Value pointed by stringREF---> " << brainRef << std::endl;
	return (0);
}