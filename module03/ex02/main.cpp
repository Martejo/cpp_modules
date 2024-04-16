#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// voir operateur assignation claptrap = scave trap ; Possible ?
int	main( void )
{
	FragTrap	frag("Bernard");
	FragTrap	copy(frag);
	ClapTrap	clap("Tapi");
	ClapTrap	*scv_ptr = &frag;

	std::cout << "\n" << std::endl;
	frag.print();
	copy.print();
	clap.print();
	std::cout << "\n!-------- FragTrap Loop Constructor/destrucor order --------!" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\n" << std::endl;
		FragTrap	loop("loop");
		loop.print();
	}
	std::cout << "\n!-------- ScavTrap Loop Constructor/destrucor order --------!" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\n" << std::endl;
		ScavTrap	loop("loop");
		loop.print();
	}

	std::cout << "\n!-------- ClapTrap Functions working on FragTrap --------!" << std::endl;
	std::cout << "\n" << std::endl;
	frag.beRepaired(1);

	std::cout << "\n" << std::endl;
	copy.takeDamage(1);

	std::cout << "\n!-------- FragTrap own attack Functions / Working on ScavTrap pointer initialized with ClapTrap --------!" << std::endl;
	std::cout << "\n" << std::endl;
	frag.attack("Bernard");
	clap.attack("Bernard");
	scv_ptr->attack("Tapi");
	std::cout << "\n!-------- FragTrap highFivesGuys Functions  --------!" << std::endl;
	std::cout << "\n" << std::endl;
	frag.highFivesGuys();
	std::cout << "\n" << std::endl;
	return (0);
}