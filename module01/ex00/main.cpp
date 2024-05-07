/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:56:40 by gemartel          #+#    #+#             */
/*   Updated: 2024/04/19 09:56:45 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>

/**
 * const std::bad_alloc& e est la déclaration de la variable e dans le bloc catch.
 * Le & indique que e est une référence à un objet de type std::bad_alloc.
 * 
 * e.what() est une méthode membre de la classe std::exception dont std::bad_alloc est dérivée.
 * Cette méthode retourne une chaîne de caractères (const char*) qui décrit l'erreur ou l'état qui a conduit à l'exception.
*/

/**
 *Le but principal de cet exercice est de comprendre quand et pourquoi utiliser l'allocation de mémoire sur la pile
 *versus sur le tas dans le contexte de la gestion des objets dans un programme C++.
*/

int main(void)
{
	Zombie *zombie;

	try{
		zombie = newZombie("Heap");
	}
	catch(const std::bad_alloc& e){
		std::cerr << "Allocation failded:" << e.what() << '\n';
	}
	zombie->announce();
	delete(zombie);
	randomChump("stack");
	return (0);
}