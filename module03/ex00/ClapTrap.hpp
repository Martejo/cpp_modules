#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string _Name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
	public:

		ClapTrap(std::string name);
		ClapTrap &operator=(const ClapTrap& a );
		ClapTrap(const ClapTrap &copy);
		ClapTrap();
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void print( void );
};




#endif
