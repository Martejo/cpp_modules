#include "HumanA.hpp"

HumanA::HumanA(std::string const &name, Weapon const &weapon) : name(name),
																weapon(weapon)
{
	return;
}

HumanA::~HumanA(void)
{
	return;
}

void HumanA::attack(void) const
{
	std::cout << this->name << " attacks with their ";
	std::cout << this->weapon.getType() << std::endl;

	return;
}