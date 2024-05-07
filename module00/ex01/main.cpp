#include "header.hpp"

int	main(void)
{
	PhoneBook book;
	std::string input = "";
	book.welcome();
	
	while (true) // Boucle infinie
	{
		std::cout << "> " << std::flush;
		if (!(std::cin >> input))
			break;
		if (input.compare("EXIT") == 0)
			break;
		else if (input.compare("ADD") == 0)
			book.addContact();
		else if (input.compare("SEARCH") == 0)
		{
			book.displayPhoneBook();
			book.searchContact();
		}
	}
	return (0);
}

/**
 * std::cin récupère l'entrée standard jusqu'à ce qu'elle rencontre un espace, une tabulation ou un retour à la ligne
*/