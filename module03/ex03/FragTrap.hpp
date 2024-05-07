#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	protected:
		int	_attackDmgHeritage;
		int	_hitPointsHeritage;
	public:
		FragTrap();
		FragTrap( std::string name );
		FragTrap( FragTrap &copy );
		FragTrap &operator=( FragTrap& a );
		~FragTrap();

		void	attack(const std::string& target);
		void	highFivesGuys();
};

#endif