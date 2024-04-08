#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(std::string const &type);
		~Weapon(void);
		std::string const &getType(void) const;
		void setType(std::string const &type);

};

#endif