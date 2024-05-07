/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:14:30 by gemartel          #+#    #+#             */
/*   Updated: 2024/05/06 12:16:04 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria* _materia[4];
	public:
		// Constructors
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		
		// Assignment operator overload
		MateriaSource& operator=(const MateriaSource& rhs);

		// Destructor
		~MateriaSource();

		void learnMateria(AMateria* m);
		AMateria* createMateria(const std::string& type);
};

#endif