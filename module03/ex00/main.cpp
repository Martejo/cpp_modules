#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	clap("Bernard");
	ClapTrap	trap;

	std::cout << "\n" << std::endl;
	clap.print();
	trap.print();

	std::cout << "\n" << std::endl;
	
	for (int i = 0; i < 11; i++)
		clap.beRepaired(1);

	std::cout << "\n" << std::endl;
	
	for (int i = 0; i < 11; i++)
		trap.takeDamage(1);
	
	std::cout << "\n" << std::endl;
	
	clap.attack("Morty");
	trap.attack("Bernard");
	trap.beRepaired(1);

	std::cout << "\n" << std::endl;
	
	return (0);
}