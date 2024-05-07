/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:58:07 by gemartel          #+#    #+#             */
/*   Updated: 2024/04/19 09:58:09 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string const &name);
	~HumanB(void);

	void setWeapon(Weapon &weapon);
	void attack(void) const;

private:
	std::string name;
	Weapon *weapon;
};

#endif