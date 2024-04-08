#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl iAmHarl;

	if (argc == 1)
		iAmHarl.complain("DEBUG");
	else
		iAmHarl.complain(argv[1]);
	return (0);
}