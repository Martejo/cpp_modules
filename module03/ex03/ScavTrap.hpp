#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	protected:
		int	_energy_points_heritage;
	public:
		ScavTrap();
		ScavTrap( std::string name );
		ScavTrap( ScavTrap &copy );
		ScavTrap &operator=( ScavTrap& a );
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();
};

#endif