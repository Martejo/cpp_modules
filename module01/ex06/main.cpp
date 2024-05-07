/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:59:16 by gemartel          #+#    #+#             */
/*   Updated: 2024/04/19 09:59:20 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl iAmHarl;

	if (argc == 1)
		iAmHarl.complain("DEBUG");
	else
		iAmHarl.complain(argv[1]);
	return (0);
}