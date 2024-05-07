/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:58:55 by gemartel          #+#    #+#             */
/*   Updated: 2024/04/19 09:58:58 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/**
 * Gestion des niveaux de log : Comprendre comment manipuler des niveaux de log différents
 * (DEBUG, INFO, WARNING, ERROR) peut être utile non seulement dans ce projet mais aussi
 * dans des applications réelles où le filtrage des messages de log est essentiel pour le diagnostic et la maintenance des systèmes.
*/

int main()
{
	Harl iAmHarl;

	iAmHarl.complain("DEBUG");
	iAmHarl.complain("INFO");
	iAmHarl.complain("WARNING");
	iAmHarl.complain("ERROR");
	return (0);
}