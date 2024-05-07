/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:57:44 by gemartel          #+#    #+#             */
/*   Updated: 2024/04/19 09:57:46 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>


Zombie *zombieHorde( int N, std::string name ) //static
{
	Zombie* horde = NULL;
	try{
		horde = new Zombie[N];
	}
	catch(const std::bad_alloc& e){
		std::cerr << "Allocation failded: " << e.what() << '\n';
		return (NULL);
	}
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}
