#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


// voir operateur assignation claptrap = scave trap ; Possible ?
int	main( void )
{
	ScavTrap	scav("Bernard");
	ScavTrap	scav2;
	ClapTrap	clap("Tapi");

	std::cout << "\nScav" << std::endl;
	scav.print();

	std::cout << "\n" << std::endl;
	for(int i = 0; i < 6; i++)
		scav.attack("Tapi");
	scav.beRepaired(1);
	scav.guardGate();
	
	std::cout << "\nClap" << std::endl;
	clap.print();
	std::cout << "\n" << std::endl;
	clap.attack("Bernard");

	std::cout << "\n" << std::endl;
	scav2.print();
	scav2.guardGate();
	scav2.takeDamage(10);
	std::cout << "\n" << std::endl;

	return (0);
}