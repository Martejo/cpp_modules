#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	FragTrap	frag("Bernard");
	std::cout << std::endl;
	ScavTrap	scav("Tapie");
	std::cout << std::endl;

	frag.print();
	std::cout << std::endl;
	scav.print();
	std::cout << std::endl;
	frag.highFivesGuys();
	std::cout << std::endl;
	scav.guardGate();
	std::cout << std::endl;
	return (0);
}