/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:23:05 by gemartel          #+#    #+#             */
/*   Updated: 2024/04/23 11:35:35 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	~DiamondTrap();
	DiamondTrap(std::string);
	DiamondTrap(const DiamondTrap &);
	DiamondTrap & operator=(const DiamondTrap &);

	void whoAmI();
	void attack(const std::string& target);
private:
	DiamondTrap();
	std::string _name;
};

#endif