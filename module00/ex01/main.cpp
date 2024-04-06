#include "header.hpp"

int	main(void)
{
	PhoneBook book;
	std::string input = "";
	book.welcome();
	
	while (input.compare("EXIT") != 0)
	{
		if (input.compare("ADD") == 0)
			book.addContact();
		else if (input.compare("SEARCH") == 0)
		{
			book.displayPhoneBook();
			book.searchContact();
		}
		std::cout << "> " << std::flush;
		std::cin >> input;
	}
	
	return (0);
}