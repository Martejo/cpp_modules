#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap( std::string name );
		ScavTrap( ScavTrap &copy );
		ScavTrap &operator=( ScavTrap& a );
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();
};

#endif