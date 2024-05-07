/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:57:38 by gemartel          #+#    #+#             */
/*   Updated: 2024/04/19 14:33:26 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

/**
 * une méthode statique en C++ est une fonction membre d'une classe qui peut être appelée
 * sans qu'une instance de cette classe soit nécessaire.
 * Elle appartient à la classe elle-même, plutôt qu'à un objet spécifique de cette classe. 
*/

class Zombie
{
private:
	std::string	_name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie(void);

	void announce(void);
	void setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif