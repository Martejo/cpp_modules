#include "Zombie.hpp"

int main(void)
{
	int	sizeHorde;
	Zombie *horde;

	sizeHorde = 5;
	horde = zombieHorde(sizeHorde, "Gumba");
	for (int i = 0; i < sizeHorde; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}