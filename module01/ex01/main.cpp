/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:57:25 by gemartel          #+#    #+#             */
/*   Updated: 2024/04/19 09:57:28 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * 
 *Cette fonction alloue dynamiquement un tableau de N objets Zombie en une seule allocation
 *et initialise chaque zombie avec le nom spécifié. Cette approche démontre l'efficacité de
 *la gestion de la mémoire et de l'initialisation des objets en C++.
 * 
 *L'utilisation de cette fonction inclut la gestion d'une séquence d'objets zombies à l'aide de pointeurs,
 *mettant l'accent sur les principes de l'allocation dynamique de la mémoire, la gestion du cycle de vie des objets,
 *et les tests de base pour la fonctionnalité et les fuites de mémoire.
 *
 *Important : les utilisateurs de cette fonction sont responsables de la désallocation de la mémoire à l'aide de delete[]
 *pour éviter les fuites de mémoire.
 * */


int main(void)
{
	int	sizeHorde;
	Zombie *horde;
	Zombie yo = Zombie("olo");

	sizeHorde = 5;
	horde = zombieHorde(sizeHorde, "Gumba");
	if (!horde)
		return (-1);
	for (int i = 0; i < sizeHorde; i++)
		horde[i].announce();
	delete[] horde;
	yo.announce();
	return (0);
}