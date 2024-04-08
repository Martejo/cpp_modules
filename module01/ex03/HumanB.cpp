#include "HumanB.hpp"

HumanB::HumanB(std::string const &name) : name(name), weapon(NULL)
{
	return;
}

HumanB::~HumanB(void)
{
	return;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;

	return;
}

void HumanB::attack(void) const
{
	std::cout << this->name << " attacks with their ";

	if (this->weapon != NULL)
		std::cout << this->weapon->getType();
	else
		std::cout << "bare hands";

	std::cout << std::endl;

	return;
}