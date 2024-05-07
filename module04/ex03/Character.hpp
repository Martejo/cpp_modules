/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:07:25 by gemartel          #+#    #+#             */
/*   Updated: 2024/05/06 13:58:38 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
	private:
		std::string _name;
		AMateria* _materia[4];

	public:
	// Constructors
	Character(const std::string& name);
	Character(const Character& other);
	
	// Assignment operator overload
	Character& operator=(const Character& rhs);

	// Destructor
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	AMateria *getMateria(int idx);
};

#endif