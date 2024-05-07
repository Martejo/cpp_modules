/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:04:13 by gemartel          #+#    #+#             */
/*   Updated: 2024/05/06 16:37:31 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"


class Cure: public AMateria
{
	public:
		// Constructors
		Cure();
		Cure(const Cure& copy);

		// Assignment operator overload
		Cure& operator=(const Cure& a);

		// Destructor
		~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif