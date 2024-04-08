#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string const &name, Weapon const &weapon);
		~HumanA(void);
		void attack(void) const;

	private:
		std::string name;
		Weapon const &weapon;
};

#endif