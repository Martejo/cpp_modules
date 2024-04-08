#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie;

	zombie = newZombie("Heap");
	zombie->announce();
	delete(zombie);
	randomChump("stack");
	return (0);
}