# include "Weapon.hpp"

Weapon::Weapon(std::string const &type)
{
	this->type = type;
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}
std::string const &Weapon::getType(void) const
{
	return (this->type);
}

void Weapon::setType(std::string const &type)
{
	this->type = type;
	return ;
}