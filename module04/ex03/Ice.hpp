/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:58:28 by gemartel          #+#    #+#             */
/*   Updated: 2024/05/06 12:19:53 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		// Constructors
		Ice();
		Ice(const Ice& copy);

		// Assignment operator overload
		Ice& operator=(const Ice& a);

		// Destructor
		~Ice();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif