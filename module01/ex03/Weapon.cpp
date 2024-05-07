/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:58:17 by gemartel          #+#    #+#             */
/*   Updated: 2024/04/19 09:58:19 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(std::string const &type)
{
	this->_type = type;
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

/**
 * Le premier const après std::string indique que la fonction retourne
 * une référence constante à un objet de type std::string.
 * Cela signifie que l'objet std::string auquel la référence
 * renvoie ne peut pas être modifié via cette référence.

 *Le deuxième const après la liste de paramètres void indique que
 *la fonction elle-même est une fonction membre constante.
 *Cela signifie que cette fonction ne modifie pas l'état de l'objet
 *sur lequel elle est appelée.
 *Elle est donc autorisée à être appelée sur des objets constants de la classe.
*/

std::string const &Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(std::string const &type)
{
	this->_type = type;
	return ;
}