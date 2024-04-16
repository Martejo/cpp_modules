#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


// voir operateur assignation claptrap = scave trap ; Possible ?
int	main( void )
{
	ScavTrap	scav("Bernard");
	ScavTrap	copy(scav);
	ClapTrap	clap("Tapi");
	ClapTrap	*scv_ptr = &scav;

	std::cout << "\n" << std::endl;
	scav.print();
	copy.print();
	clap.print();

	std::cout << "\n!-------- ScavTrap Loop Constructor/destrucor order --------!" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\n" << std::endl;
		ScavTrap	loop("loop");
		loop.print();
	}

	std::cout << "\n!-------- ClapTrap Functions working on ScavTrap --------!" << std::endl;
	std::cout << "\n" << std::endl;
	scav.beRepaired(1);

	std::cout << "\n" << std::endl;
	copy.takeDamage(1);

	std::cout << "\n!-------- ScavTrap own attack Functions / Working on ScavTrap pointer initialized with ClapTrap --------!" << std::endl;
	std::cout << "\n" << std::endl;
	scav.attack("Bernard");
	clap.attack("Bernard");
	scv_ptr->attack("Tapi");

	std::cout << "\n!-------- ScavTrap highFivesGuys Functions  --------!" << std::endl;
	std::cout << "\n" << std::endl;
	scav.guardGate();
	std::cout << "\n" << std::endl;
	return (0);
}